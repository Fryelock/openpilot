from selfdrive.car.subaru.values import CAR, DBC

# ES_LKAS = 34 11 00 00 00 00 00 00

# BO_ 290 ES_LKAS: 8 XXX
# SG_ Checksum : 0|8@1+ (1,0) [0|255] "" XXX
#  SG_ Counter : 8|4@1+ (1,0) [0|15] "" XXX
#  SG_ LKAS_Output : 16|13@1- (-1,0) [0|3] "" XXX
#  SG_ LKAS_Request : 29|1@0+ (1,0) [0|3] "" XXX
#  SG_ SET_1 : 12|1@0+ (1,0) [0|3] "" XXX

# SG_ signal : start bit|num bits@little endian(1) unsigned(+) (scaling) [min|max] "units"

def create_steering_control(packer, car_fingerprint, idx, steer1, byte2, checksum):
  if car_fingerprint == CAR.OUTBACK:
    values = {
      "Byte0": idx,
      "Byte1": steer1,
      "Byte2": byte2,
      "Byte3": 1 if steer1 + byte2 != 0 else 0,
      "Checksum": checksum
    }
    
  if car_fingerprint == CAR.XV2018:
    values = {
      "Checksum": checksum,
      "Byte1": idx,
      "Byte2": steer1,
      "Byte3": byte2
    }

  #print("checksum " + str(checksum) + " idx " + str(idx) + " steer1 " + str(steer1) + " byte2 " + str(byte2))

  return packer.make_can_msg("ES_LKAS_2015", 0, values)

def create_openpilot_active(packer):
  values = {
    "ACTIVE": 1
  }

  return packer.make_can_msg("OP_ACTIVE", 0, values)
