from common.numpy_fast import clip, interp
from common.realtime import sec_since_boot
from selfdrive.config import Conversions as CV
from selfdrive.boardd.boardd import can_list_to_can_capnp
from selfdrive.car.subaru.carstate import CarState, get_powertrain_can_parser
from selfdrive.car.subaru import subarucan
from selfdrive.car.subaru.values import CAR, DBC
from selfdrive.can.packer import CANPacker


class CarControllerParams():
  def __init__(self, car_fingerprint):
    self.STEER_MAX = 2047              # max_steer 4095 
    self.STEER_STEP = 2                # how often we update the steer cmd
    self.STEER_DELTA_UP = 25           # torque increase per refresh
    self.STEER_DELTA_DOWN = 25         # torque decrease per refresh
    if car_fingerprint == CAR.OUTBACK:
      self.STEER_DRIVER_ALLOWANCE = 2000   # allowed driver torque before start limiting
    else:
      self.STEER_DRIVER_ALLOWANCE = 250   # allowed driver torque before start limiting
    self.STEER_DRIVER_MULTIPLIER = 10   # weight driver torque heavily
    self.STEER_DRIVER_FACTOR = 60       # from subaru_safety
    


class CarController(object):
  def __init__(self, car_fingerprint):
    self.start_time = sec_since_boot()
    self.lkas_active = False
    self.steer_idx = 0
    self.apply_steer_last = 0
    self.car_fingerprint = car_fingerprint

    # Setup detection helper. Routes commands to
    # an appropriate CAN bus number.
    self.params = CarControllerParams(car_fingerprint)
    print(DBC)
    self.packer_pt = CANPacker(DBC[car_fingerprint]['pt'])

  def update(self, sendcan, enabled, CS, frame, actuators):
    """ Controls thread """

    P = self.params

    # Send CAN commands.
    can_sends = []

    ### STEER ###

    if (frame % P.STEER_STEP) == 0:
    
      final_steer = actuators.steer if enabled else 0.
      apply_steer = final_steer * P.STEER_MAX
      # limits due to driver torque
      driver_max_torque = P.STEER_MAX + (P.STEER_DRIVER_ALLOWANCE + CS.steer_torque_driver * P.STEER_DRIVER_FACTOR) * P.STEER_DRIVER_MULTIPLIER
      driver_min_torque = -P.STEER_MAX + (-P.STEER_DRIVER_ALLOWANCE + CS.steer_torque_driver * P.STEER_DRIVER_FACTOR) * P.STEER_DRIVER_MULTIPLIER
      max_steer_allowed = max(min(P.STEER_MAX, driver_max_torque), 0)
      min_steer_allowed = min(max(-P.STEER_MAX, driver_min_torque), 0)
      apply_steer = clip(apply_steer, min_steer_allowed, max_steer_allowed)

      # slow rate if steer torque increases in magnitude
      if self.apply_steer_last > 0:
        apply_steer = clip(apply_steer, max(self.apply_steer_last - P.STEER_DELTA_DOWN, -P.STEER_DELTA_UP), self.apply_steer_last + P.STEER_DELTA_UP)
      else:
        apply_steer = clip(apply_steer, self.apply_steer_last - P.STEER_DELTA_UP, min(self.apply_steer_last + P.STEER_DELTA_DOWN, P.STEER_DELTA_UP))

      apply_steer = int(round(apply_steer))
      self.apply_steer_last = apply_steer
      
      
      lkas_enabled = enabled and not CS.steer_not_allowed and CS.v_ego >= 10.

      if not lkas_enabled:
          apply_steer = 0

      if (self.car_fingerprint == CAR.OUTBACK):
        
        if apply_steer != 0:
          chksm_steer = apply_steer * -1
          chksm_engage = 1
        else:
          chksm_steer = 0
          chksm_engage = 0
        
        #counts from 0 to 7 then back to 0
        idx = (frame / P.STEER_STEP) % 8
        steer2 = (chksm_steer >> 8) & 0x1F
        steer1 =  chksm_steer - (steer2 << 8)
        byte2 = steer2
        checksum = (idx + steer2 + steer1 + chksm_engage) % 256
        
      if (self.car_fingerprint == CAR.XV2018):
      
        #counts from 0 to 15 then back to 0 + 16 for enable bit
        
        chksm_steer = apply_steer * -1
        if chksm_steer != 0:
          left3 = 32
        else:
          left3 = 0

        idx = ((frame / P.STEER_STEP) % 16) + 16
        steer2 = (chksm_steer >> 8) & 0x1F
        steer1 =  chksm_steer - (steer2 << 8)
        byte2 = steer2 + left3

        checksum = ((idx + steer1 + byte2) % 256) + 35

      print('enabled: ' + str(enabled) + ' chksm_steer: ' + str(chksm_steer) + ' apply_steer ' + str(apply_steer) + ' actuators.steer ' + str(actuators.steer))

      can_sends.append(subarucan.create_steering_control(self.packer_pt, CS.CP.carFingerprint, idx, steer1, byte2, checksum))
      can_sends.append(subarucan.create_openpilot_active(self.packer_pt))


    sendcan.send(can_list_to_can_capnp(can_sends, msgtype='sendcan').to_bytes())
