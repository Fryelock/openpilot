from selfdrive.car.subaru.values import CAR, DBC

def create_steering_control(packer, car_fingerprint, idx, steer, checksum):
  if car_fingerprint in (CAR.XV, CAR.IMPREZA):
    values = {
      "Counter": idx,
      "LKAS_Output": steer,
      "LKAS_Request": 1 if steer != 0 else 0,
      "Checksum": checksum,
      "SET_1": 1
    }
  return packer.make_can_msg("ES_LKAS", 0, values)

def create_openpilot_active(packer):
  values = {
    "ACTIVE": 1
  }
  return packer.make_can_msg("OP_ACTIVE", 0, values)

