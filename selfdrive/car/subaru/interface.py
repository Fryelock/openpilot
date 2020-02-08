#!/usr/bin/env python3
from cereal import car
from selfdrive.car.subaru.values import CAR
from selfdrive.car import STD_CARGO_KG, scale_rot_inertia, scale_tire_stiffness, gen_empty_fingerprint
from selfdrive.car.interfaces import CarInterfaceBase

class CarInterface(CarInterfaceBase):

  @staticmethod
  def compute_gb(accel, speed):
    return float(accel) / 4.0

  @staticmethod
  def get_params(candidate, fingerprint=gen_empty_fingerprint(), has_relay=False, car_fw=[]):
    ret = CarInterfaceBase.get_std_params(candidate, fingerprint, has_relay)

    ret.carName = "subaru"
    ret.radarOffCan = True
    ret.safetyModel = car.CarParams.SafetyModel.subaru

    # Subaru port is a community feature, since we don't own one to test
    ret.communityFeature = True

    # force openpilot to fake the stock camera, since car harness is not supported yet and old style giraffe (with switches)
    # was never released
    ret.enableCamera = True

    ret.steerRateCost = 0.7
    ret.steerLimitTimer = 0.4

    if candidate == CAR.IMPREZA:
      ret.mass = 1568. + STD_CARGO_KG
      ret.wheelbase = 2.67
      ret.centerToFront = ret.wheelbase * 0.5
      ret.steerRatio = 15
      tire_stiffness_factor = 1.0
      ret.steerActuatorDelay = 0.4   # end-to-end angle controller
      ret.lateralTuning.pid.kf = 0.00005
      ret.lateralTuning.pid.kiBP, ret.lateralTuning.pid.kpBP = [[0., 20.], [0., 20.]]
      ret.lateralTuning.pid.kpV, ret.lateralTuning.pid.kiV = [[0.2, 0.3], [0.02, 0.03]]
      ret.steerMaxBP = [0.] # m/s
      ret.steerMaxV = [1.]

    ret.steerControlType = car.CarParams.SteerControlType.torque
    ret.steerRatioRear = 0.

    if candidate == CAR.OUTBACK:
      ret.mass = 1568 + STD_CARGO_KG
      ret.wheelbase = 2.67
      ret.centerToFront = ret.wheelbase * 0.5
      ret.steerRatio = 20            # learned, 14 stock
      tire_stiffness_factor = 1.9
      ret.steerActuatorDelay = 0.4
      ret.lateralTuning.pid.kf = 0.000028
      ret.lateralTuning.pid.kiBP, ret.lateralTuning.pid.kpBP = [[0.,10.], [0.,10.]]
      ret.lateralTuning.pid.kpV, ret.lateralTuning.pid.kiV = [[0.07,0.15], [0.02,0.02]]
      ret.steerMaxBP = [0.] # m/s
      ret.steerMaxV = [1.]

    if candidate == CAR.LEGACY:
      ret.mass = 1568 + STD_CARGO_KG
      ret.wheelbase = 2.67
      ret.centerToFront = ret.wheelbase * 0.5
      # Hassan Legacy 2018
      ret.steerRatio = 12.5
      tire_stiffness_factor = 1.0
      # Hassan Legacy 2018
      ret.steerActuatorDelay = 0.155
      ret.lateralTuning.pid.kf = 0.00005
      ret.lateralTuning.pid.kiBP, ret.lateralTuning.pid.kpBP = [[0., 20.], [0., 20.]]
      ret.lateralTuning.pid.kpV, ret.lateralTuning.pid.kiV = [[0.1, 0.2], [0.0078, 0.019]]
      ret.steerMaxBP = [0.] # m/s
      ret.steerMaxV = [1.]

    # testing tuning

    # No long control in subaru
    ret.gasMaxBP = [0.]
    ret.gasMaxV = [0.]
    ret.brakeMaxBP = [0.]
    ret.brakeMaxV = [0.]
    ret.longitudinalTuning.deadzoneBP = [0.]
    ret.longitudinalTuning.deadzoneV = [0.]
    ret.longitudinalTuning.kpBP = [0.]
    ret.longitudinalTuning.kpV = [0.]
    ret.longitudinalTuning.kiBP = [0.]
    ret.longitudinalTuning.kiV = [0.]

    # end from gm

    # TODO: get actual value, for now starting with reasonable value for
    # civic and scaling by mass and wheelbase
    ret.rotationalInertia = scale_rot_inertia(ret.mass, ret.wheelbase)

    # TODO: start from empirically derived lateral slip stiffness for the civic and scale by
    # mass and CG position, so all cars will have approximately similar dyn behaviors
    ret.tireStiffnessFront, ret.tireStiffnessRear = scale_tire_stiffness(ret.mass, ret.wheelbase, ret.centerToFront, tire_stiffness_factor=tire_stiffness_factor)

    return ret

  # returns a car.CarState
  def update(self, c, can_strings):
    self.cp.update_strings(can_strings)
    self.cp_cam.update_strings(can_strings)

    ret = self.CS.update(self.cp, self.cp_cam)

    ret.canValid = self.cp.can_valid and self.cp_cam.can_valid
    ret.steeringRateLimited = self.CC.steer_rate_limited if self.CC is not None else False

    buttonEvents = []
    be = car.CarState.ButtonEvent.new_message()
    be.type = car.CarState.ButtonEvent.Type.accelCruise
    buttonEvents.append(be)

    ret.events = self.create_common_events(ret).to_msg()

    self.CS.out = ret.as_reader()
    return self.CS.out

  def apply(self, c):
    can_sends = self.CC.update(c.enabled, self.CS, self.frame, c.actuators,
                               c.cruiseControl.cancel, c.hudControl.visualAlert,
                               c.hudControl.leftLaneVisible, c.hudControl.rightLaneVisible)
    self.frame += 1
    return can_sends
