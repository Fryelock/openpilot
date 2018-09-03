from selfdrive.car.subaru.values import CAR, DBC

def create_steering_control(packer, bus, car_fingerprint, idx, steer1, byte2, checksum):
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

  return packer.make_can_msg("ES_LKAS", 0, values)