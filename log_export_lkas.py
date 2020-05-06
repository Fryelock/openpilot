from tools.lib.logreader import LogReader
from tools.lib.route import Route
from cereal import log as capnp_log
from collections import defaultdict
import cantools
import sys

route_id = sys.argv[1]
dbc_file = 'opendbc/subaru_crosstrek_2018.dbc'
route = Route(route_id)

signals = [
  (128, 290, "ES_LKAS", "LKAS_Output"),
  (128, 801, "ES_DashStatus", "Cruise_Activated"),
  (128, 545, "ES_Distance", "Signal3"),
  (  0, 281, "Steering_Torque", "Steer_Error_1"),
  (  0, 281, "Steering_Torque", "Steer_Warning"),
  (  0, 281, "Steering_Torque", "Steering_Angle"),
  (  0, 281, "Steering_Torque", "Steer_Torque_Output"),
]

keys = ['Cruise_Activated', 'Steer_Error_1', 'Steer_Warning', 'Signal3', 'LKAS_Output', 'Steering_Angle', 'Steer_Torque_Output']

dbc = cantools.database.load_file(dbc_file)
table = defaultdict(dict)
can_msg = defaultdict(dict)
prev_logMonoTime = 0 

for i in signals:
  msg = i[2]
  can_msg[msg] = dbc.get_message_by_name(msg)

log_paths = route.log_paths()

comma = ","
print('logMonoTime,' + comma.join(keys))

for log_path in log_paths:
  #print(log_path)
  lr = LogReader(log_path)

  for log_msg in lr:
    msg_type = log_msg.which()
    #print(msg_type)
    if msg_type == 'can':
      for rec in log_msg.can:
        for s in signals:
          bus, addr, msg, signal = list(s)
          if (bus == rec.src and addr == rec.address):
            table[log_msg.logMonoTime][signal] = can_msg[msg].decode(rec.dat)[signal]
            #print("%s: %s" % (signal, can_msg[msg].decode(rec.dat)[signal]))

    if prev_logMonoTime != log_msg.logMonoTime and len(table) > 0 :
      for time, items in table.items():
        result = str(time)
        for k in keys:
          #print(items[k])
          try:
            result += "," + str(items[k])
          except KeyError:
            result += ","
        print(result)
      table = defaultdict(dict)

    prev_logMonoTime = log_msg.logMonoTime

