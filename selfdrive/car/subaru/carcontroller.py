#from common.numpy_fast import clip
from selfdrive.car import apply_std_steer_torque_limits
from selfdrive.car.subaru import subarucan
from selfdrive.car.subaru.values import DBC, CAR
from opendbc.can.packer import CANPacker


class CarControllerParams():
  def __init__(self, car_fingerprint):
    self.STEER_MAX = 2047              # max_steer 4095
    self.STEER_STEP = 2                # how often we update the steer cmd
    self.STEER_DELTA_UP = 50           # torque increase per refresh, 0.8s to max
    self.STEER_DELTA_DOWN = 70         # torque decrease per refresh
    if car_fingerprint == CAR.IMPREZA:
      self.STEER_DRIVER_ALLOWANCE = 60   # allowed driver torque before start limiting
      self.STEER_DRIVER_MULTIPLIER = 10  # weight driver torque heavily
      self.STEER_DRIVER_FACTOR = 1       # from dbc
      self.SNG_DISTANCE = 170            # Trigger value for Close_Distance (0-255)
    if car_fingerprint in (CAR.OUTBACK, CAR.LEGACY):
      self.STEER_DRIVER_ALLOWANCE = 300  # allowed driver torque before start limiting
      self.STEER_DRIVER_MULTIPLIER = 1   # weight driver torque heavily
      self.STEER_DRIVER_FACTOR = 1       # from dbc
      self.STEER_DELTA_DOWN = 60         # torque decrease per refresh



class CarController():
  def __init__(self, dbc_name, CP, VM):
    self.lkas_active = False
    self.apply_steer_last = 0
    self.es_distance_cnt = -1
    self.es_lkas_cnt = -1
    self.brake_cnt = -1
    self.steer_rate_limited = False
    self.sng_resume_acc = False
    self.sng_cancel_acc = False
    self.sng_resume_cnt = -1
    self.sng_cancel_cnt = -1
    self.prev_close_distance = 0
    self.prev_wipers = 0

    # Setup detection helper. Routes commands to
    # an appropriate CAN bus number.
    self.params = CarControllerParams(CP.carFingerprint)
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

      if CS.CP.carFingerprint in (CAR.OUTBACK, CAR.LEGACY):

        # add noise to prevent lkas fault from constant torque value for over 1s
        if enabled and apply_steer == self.apply_steer_last:
          self.counter =+ 1
          if self.counter == 50:
            apply_steer = round(int(apply_steer * 0.99))
        else:
          self.counter = 0

      can_sends.append(subarucan.create_steering_control(self.packer, CS.CP.carFingerprint, apply_steer, frame, P.STEER_STEP))

      self.apply_steer_last = apply_steer

    if CS.CP.carFingerprint == CAR.IMPREZA:
      '''
      if (frame % 10) == 0:
        print("brake_pedal: %s cruise_state: %s car_follow %s close_dist: %s prev_close_dist: %s sng_resume: %s sng_cancel: %s" % (CS.brake_pedal, CS.cruise_state, CS.car_follow, CS.close_distance, self.prev_close_distance, self.sng_resume_acc, self.sng_cancel_acc))

      # Manual trigger using wipers signal
      if CS.wipers and not self.prev_wipers:
        self.sng_cancel_acc = True
        self.sng_resume_acc = False
        print("wipers cancel acc")
      self.prev_wipers = CS.wipers
      '''

      # Trigger sng_cancel_acc when in hold and close_distance increases > SNG_DISTANCE
      # FIXME: scale SNG_DISTANCE according to ES_DashStatus Cruise_Distance bars setting
      # Cruise_Distance = 2: 90 (level), 160 (hill)
      if (enabled
          and CS.cruise_state == 3
          and CS.close_distance > P.SNG_DISTANCE
          and CS.close_distance < 255
          and self.prev_close_distance < CS.close_distance
          and CS.car_follow == 1
          and not self.sng_cancel_acc):
        self.sng_cancel_acc = True
        self.sng_resume_acc = False
        print("set sng_cancel_acc")

      self.prev_close_distance = CS.close_distance

      if self.es_distance_cnt != CS.es_distance_msg["Counter"]:

        # send pcm_resume_cmd to resume acc after canceling when cruise_state is ready
        if self.sng_resume_acc:
          if CS.cruise_state == 2 and self.sng_resume_cnt < 10:
              pcm_resume_cmd = True
              self.sng_resume_cnt += 1
              print("send pcm_resume_cmd")
          else:
              self.sng_resume_acc = False
              self.sng_resume_cnt = -1
              print("unset sng_resume_acc")

        can_sends.append(subarucan.create_es_distance(self.packer, CS.es_distance_msg, pcm_cancel_cmd, pcm_resume_cmd))
        self.es_distance_cnt = CS.es_distance_msg["Counter"]

      if self.es_lkas_cnt != CS.es_lkas_msg["Counter"]:
        can_sends.append(subarucan.create_es_lkas(self.packer, CS.es_lkas_msg, visual_alert, left_line, right_line))
        self.es_lkas_cnt = CS.es_lkas_msg["Counter"]

      if self.brake_cnt != CS.brake_msg["Counter"]:
        # send brake_cmd to cancel acc in hold
        if self.sng_cancel_acc:
          if self.sng_cancel_cnt < 50:
              brake_cmd = True
              self.sng_cancel_cnt += 1
              print("send brake_cmd")
          else:
              self.sng_cancel_acc = False
              self.sng_resume_acc = True
              self.sng_cancel_cnt = -1
              print("set sng_resume_acc")
              print("unset sng_cancel_acc")

        can_sends.append(subarucan.create_brake(self.packer, CS.brake_msg, brake_cmd))
        self.brake_cnt = CS.brake_msg["Counter"]

    # FIXME: ES fault on accel pedal press (Legacy 2018)
    elif CS.CP.carFingerprint in (CAR.OUTBACK) and pcm_cancel_cmd:
      can_sends.append(subarucan.create_door_control(self.packer, CS.body_info_msg))
    return can_sends

