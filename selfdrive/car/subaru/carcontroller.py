#from common.numpy_fast import clip
from selfdrive.car import apply_std_steer_torque_limits
from selfdrive.car.subaru import subarucan
from selfdrive.car.subaru.values import DBC
from opendbc.can.packer import CANPacker


class CarControllerParams():
  def __init__(self):
    self.STEER_MAX = 2047              # max_steer 4095
    self.STEER_STEP = 2                # how often we update the steer cmd
    self.STEER_DELTA_UP = 50           # torque increase per refresh, 0.8s to max
    self.STEER_DELTA_DOWN = 70         # torque decrease per refresh
    self.STEER_DRIVER_ALLOWANCE = 60   # allowed driver torque before start limiting
    self.STEER_DRIVER_MULTIPLIER = 10  # weight driver torque heavily
    self.STEER_DRIVER_FACTOR = 1       # from dbc
    self.SNG_DISTANCE = 170            # distance trigger value for stop and go (0-255)
    self.SNG_CANCEL_LIMIT = 70         # number of brake messages to cancel acc in hold
    self.SNG_RESUME_LIMIT = 5          # number of acc resume messages to send


class CarController():
  def __init__(self, dbc_name, CP, VM):
    self.lkas_active = False
    self.apply_steer_last = 0
    self.es_distance_cnt = -1
    self.es_lkas_cnt = -1
    self.steer_rate_limited = False
    self.sng_resume_acc = False
    self.sng_cancel_acc = False
    self.sng_cancel_acc_done = False
    self.manual_hold = False
    self.sng_resume_cnt = -1
    self.sng_cancel_cnt = -1
    self.brake_cnt = -1
    self.prev_close_distance = 0
    self.prev_cruise_state = 0

    self.params = CarControllerParams()
    self.packer = CANPacker(DBC[CP.carFingerprint]['pt'])

  def update(self, enabled, CS, frame, actuators, pcm_cancel_cmd, visual_alert, left_line, right_line):
    """ Controls thread """

    P = self.params
    pcm_resume_cmd = False
    brake_cmd = False

    # Send CAN commands.
    can_sends = []

    ### STEER ###

    if (frame % P.STEER_STEP) == 0:

      final_steer = actuators.steer if enabled else 0.
      apply_steer = int(round(final_steer * P.STEER_MAX))

      # limits due to driver torque

      new_steer = int(round(apply_steer))
      apply_steer = apply_std_steer_torque_limits(new_steer, self.apply_steer_last, CS.out.steeringTorque, P)
      self.steer_rate_limited = new_steer != apply_steer

      if not enabled:
        apply_steer = 0

      can_sends.append(subarucan.create_steering_control(self.packer, apply_steer, frame, P.STEER_STEP))

      self.apply_steer_last = apply_steer

    ### Stop and Go ###

    # Resume ACC automatically when in hold and car in front starts moving forward
    # Requires electric parking brake which can hold the car stopped >3 sec
    #
    # - record manual hold set in standstill with no car in front
    # - if gas or brake is pressed then cancel stop and go sequence (safety)
    #
    # - if acc is in hold, not manual hold and close distance to car in front increases > 170:
    #   send 70 brake_pedal messages to eyesight with brake_pedal = 5 and brake_pedal_on = 1 to cancel hold
    #
    # - if cruise state becomes ready after canceling hold:
    #   send 5 es_distance messages to car with cruise_resume = 1 to resume acc

    # Record manual hold set while in standstill and no car in front
    if CS.out.standstill and self.prev_cruise_state == 1 and CS.cruise_state == 3 and CS.car_follow == 0:
      self.manual_hold = True

    # Cancel manual hold when car starts moving
    if not CS.out.standstill:
      self.manual_hold = False

    # SNG: trigger ACC cancel when in hold and close_distance increases > SNG_DISTANCE
    if (enabled and CS.cruise_state == 3
        and CS.close_distance > P.SNG_DISTANCE
        and CS.close_distance < 255
        and self.prev_close_distance < CS.close_distance
        and CS.car_follow == 1
        and not self.manual_hold
        and not self.sng_cancel_acc):
      self.sng_cancel_acc = True
      self.sng_resume_acc = False

    self.prev_close_distance = CS.close_distance
    self.prev_cruise_state = CS.cruise_state

    # SNG: trigger ACC resume when cruise state becomes ready
    if (self.sng_cancel_acc_done and CS.cruise_state == 2):
      self.sng_resume_acc = True
      self.sng_cancel_acc_done = False

    # SNG: stop the SNG sequence on brake or gas press
    if CS.out.brakePressed or CS.out.gasPressed:
      self.sng_cancel_acc = False
      self.sng_resume_acc = False
      self.sng_cancel_acc_done = False

    if self.brake_cnt != CS.brake_msg["Counter"]:
      # SNG: send brake_cmd to cancel acc in hold
      if self.sng_cancel_acc:
        if self.sng_cancel_cnt < P.SNG_CANCEL_LIMIT:
            brake_cmd = True
            self.sng_cancel_cnt += 1
        else:
            self.sng_cancel_acc = False
            self.sng_cancel_acc_done = True
            self.sng_cancel_cnt = -1
      can_sends.append(subarucan.create_brake(self.packer, CS.brake_msg, brake_cmd))
      self.brake_cnt = CS.brake_msg["Counter"]

    if self.es_distance_cnt != CS.es_distance_msg["Counter"]:
      # SNG: send pcm_resume_cmd to reenable ACC and openpilot
      if self.sng_resume_acc:
        if self.sng_resume_cnt < P.SNG_RESUME_LIMIT:
            pcm_resume_cmd = True
            self.sng_resume_cnt += 1
        else:
            self.sng_resume_acc = False
            self.sng_resume_cnt = -1
      can_sends.append(subarucan.create_es_distance(self.packer, CS.es_distance_msg, pcm_cancel_cmd, pcm_resume_cmd))
      self.es_distance_cnt = CS.es_distance_msg["Counter"]

    if self.es_lkas_cnt != CS.es_lkas_msg["Counter"]:
      can_sends.append(subarucan.create_es_lkas(self.packer, CS.es_lkas_msg, visual_alert, left_line, right_line))
      self.es_lkas_cnt = CS.es_lkas_msg["Counter"]

    return can_sends
