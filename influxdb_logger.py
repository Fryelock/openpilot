#!/usr/bin/env python
import zmq
import time
import numpy as np
import requests
import selfdrive.messaging as messaging
from selfdrive.services import service_list
from selfdrive.controls.lib.latcontrol_helpers import calc_lookahead_offset
from selfdrive.controls.lib.pathplanner import PathPlanner
from selfdrive.controls.lib.vehicle_model import VehicleModel
from common.realtime import set_realtime_priority, Ratekeeper
from cereal import car
from common.params import Params
#import pprint

# based on https://github.com/Gernby/OpenPilot_Dashboard/blob/master/dashboard.py

def dashboard_thread(rate=100):
  set_realtime_priority(3)

  # influxdb http api location, change the ip address to match yours
  url_string = 'http://192.168.43.197:8086/write?db=carDB'
  # influxdb measurement (table) name
  measurement= "op_lateral"
 
  # zmq
  ipaddress = "127.0.0.1"

  context = zmq.Context()
  poller = zmq.Poller()

  # selfdrive/service_list.yaml
  carState = messaging.sub_sock(context, service_list['carState'].port, addr=ipaddress, conflate=True, poller=poller)
  live100 = messaging.sub_sock(context, service_list['live100'].port, addr=ipaddress, conflate=True, poller=poller)
  vEgo = 0.0

  _live100 = None
  _carState = None

  frame_count = 0
  sample_str = ""
  influxLineString = ""

  current_rate = rate
  rk = Ratekeeper(current_rate, print_delay_threshold=np.inf)
  print("waiting for CarParams..")
  CP = car.CarParams.from_bytes(Params().get("CarParams", block=True))
  #pprint.pprint(CP)
  print("Got CarParams for %s" % (CP.carFingerprint))

  # capnp objects and field names:
  # cereal/car.capnp
  # cereal/log.capnp
  print("Starting zmq polling loop")
  while 1:
    receiveTime = int(time.time() * 1000000000)
    for socket, event in poller.poll(0):
      if socket is live100:
        _live100 = messaging.recv_one(socket)
        vEgo = _live100.live100.vEgo
        if vEgo > 0:
          if sample_str != "":
              sample_str += ","

          sample_str += ("angleSteersDes=%f,angleSteers=%f,vEgo=%f,steerOverride=%f,upSteer=%f,uiSteer=%f,ufSteer=%f,cumLagMs=%f,vCruise=%f" %
                      (_live100.live100.angleSteersDes, 
                       _live100.live100.angleSteers, 
                       _live100.live100.vEgo, 
                       _live100.live100.steerOverride, 
                       _live100.live100.upSteer, 
                       _live100.live100.uiSteer, 
                       _live100.live100.ufSteer, 
                       _live100.live100.cumLagMs, 
                       _live100.live100.vCruise))

        #print(_live100)
      elif socket is carState:
        _carState = messaging.recv_one(socket)
        if vEgo > 0:
          if sample_str != "":
              sample_str += ","
          # steeringRequested is apply_steer
          # steeringActuators is actuators.steer
          sample_str += ("steeringTorque=%f,steeringRate=%f,steeringRequested=%f,steeringActuators=%f,yawRate=%f" % 
                        (_carState.carState.steeringTorque, 
                         _carState.carState.steeringRate, 
                         _carState.carState.steeringRequested, 
                         _carState.carState.steeringActuators, 
                         _carState.carState.yawRate))
      # add CarParams as reference data
      if vEgo > 0:
        if sample_str != "":
            sample_str += ","
        # TODO: generate steerKxV dynamically, add steerKxBP
        sample_str += ("steerActuatorDelay=%f,steerRateCost=%f,steerKf=%f,steerKpV_1=%f,steerKpV_2=%f,steerKiV_1=%f,steerKiV_2=%f" % 
                      (CP.steerActuatorDelay, 
                       CP.steerRateCost,
                       CP.steerKf,
                       CP.steerKpV[0],
                       CP.steerKpV[1],
                       CP.steerKiV[0],
                       CP.steerKiV[1]))
 
    if sample_str != "":
        influxLineString += ("%s,sources=capnp,carName=%s %s %s\n" % (measurement, CP.carName, sample_str, receiveTime))
        #print(influxLineString)
        frame_count += 1
        sample_str = ""

    # post every 5 frames
    if frame_count >= 4:
        try:
            r = requests.post(url_string, data=influxLineString)
            if current_rate != rate:
              current_rate = rate
              rk = Ratekeeper(current_rate, print_delay_threshold=np.inf)
            print ('%d %d' % (frame_count, len(influxLineString)))
        except:
            if current_rate != 1:
              current_rate = 1
              rk = Ratekeeper(current_rate, print_delay_threshold=np.inf)
            continue
        frame_count = 0
        can_count = 0
        influxLineString = ""

    rk.keep_time()

def main(rate=200):
  dashboard_thread(rate)

if __name__ == "__main__":
  main()
