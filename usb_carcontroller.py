#!/usr/bin/env python
from evdev import InputDevice
from select import select
import time
import numpy as np
import zmq

from cereal import car

import selfdrive.messaging as messaging
from selfdrive.services import service_list
from selfdrive.car.car_helpers import get_car
from selfdrive.controls.lib.alertmanager import AlertManager
from common.realtime import Ratekeeper
from common.numpy_fast import clip

if __name__ == "__main__":

  # allow active controls
  passive = False
  # ***** connect to joystick *****
  # USB Gamepad Controller
  dev = InputDevice("/dev/input/event1")
  print "USB Controller"
  print dev

  button_values = [0]*13
  axis_values = [0]*7

  # ***** connect to car *****
  context = zmq.Context()
  logcan = messaging.sub_sock(context, service_list['can'].port)
  sendcan = messaging.pub_sock(context, service_list['sendcan'].port)

  CI, CP = get_car(logcan, sendcan, 1.0 if passive else None)
  AM = AlertManager()

  rk = Ratekeeper(100)

  while 1:
    # **** handle joystick ****
    r, w, x = select([dev], [], [], 0.0)
    if dev in r:
      for event in dev.read():
        print "USB Controller event"
        print event
        ## Button events
        if event.type == 1:
          # 287 is base id-1 for first button
          btn = event.code - 287
          if btn >= 1 and btn < 13:
            button_values[btn] = int(event.value)

        # # Axis move events
        if event.type == 3:
          ## Left Joystick
          if event.code == 0:
            axis_values[event.code] = np.clip(-event.value/255.0, -1.0, 1.0)
          elif event.code == 1:
            axis_values[event.code] = np.clip(-event.value/255.0, -1.0, 1.0)
          ## Left and Right Triggers
          elif event.code in [2,5]:
            if event.code == 2:
                event.value = -event.value
            axis_values[2] = np.clip(event.value/255.0, -1.0, 1.0)
          ## Right Joystick
          elif event.code == 3:
            axis_values[event.code] = np.clip(-event.value/255.0, -1.0, 1.0)
          elif event.code == 4:
            axis_values[event.code] = np.clip(-event.value/255.0, -1.0, 1.0)
          ## D-Pad (left)
          elif event.code == 16:
            print event.value
            axis_values[5] = -int(event.value)
          elif event.code == 17:
            axis_values[6] = -int(event.value)

    print axis_values, button_values

    # ***** control the car *****

    CC = car.CarControl.new_message()

    if not passive:

      AM.add("startup", False)
      actuators = car.CarControl.Actuators.new_message()

      actuators.gas = float(np.clip(-axis_values[0], 0, 1.0))
      actuators.brake = float(np.clip(axis_values[0], 0, 1.0))
      actuators.steer = float(axis_values[2])

      CC.enabled = True

      CC.actuators = actuators

      # CC.cruiseControl.override = True
      CC.cruiseControl.override = bool(button_values[1])
      CC.cruiseControl.cancel = bool(button_values[3])
      # always cancel if we have an interceptor
      #CC.cruiseControl.cancel = not CP.enableCruise or (not isEnabled(state) and CS.cruiseState.enabled)

      # brake discount removes a sharp nonlinearity
      brake_discount = (1.0 - clip(actuators.brake*3., 0.0, 1.0))
      CC.cruiseControl.speedOverride = 0.0
      CC.cruiseControl.accelOverride = 0.0
      #CC.cruiseControl.speedOverride = float(max(0.0, (LoC.v_pid + CS.cruiseState.speedOffset) * brake_discount) if CP.enableCruise else 0.0)
      #CC.cruiseControl.accelOverride = CI.calc_accel_override(CS.aEgo, plan.aTarget, CS.vEgo, plan.vTarget)
  
      CC.hudControl.setSpeed = float(axis_values[2] * 100.0)
      CC.hudControl.speedVisible = bool(button_values[2])
      CC.hudControl.lanesVisible = bool(button_values[4])
      CC.hudControl.leadVisible = bool(button_values[5])

      #CC.hudControl.setSpeed = float(v_cruise_kph * CV.KPH_TO_MS)
      #CC.hudControl.speedVisible = isEnabled(state)
      #CC.hudControl.lanesVisible = isEnabled(state)
      #CC.hudControl.leadVisible = plan.hasLead

      CC.hudControl.visualAlert = "none"
      CC.hudControl.audibleAlert = "none"

      # send car controls over can
      CI.apply(CC)
  
      CS = CI.update(CC)

      print "DEBUG: CarControls"
      #print CC

      print "DEBUG: CarState"
      print CS

    rk.keep_time()
