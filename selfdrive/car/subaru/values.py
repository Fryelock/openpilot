# flake8: noqa

from selfdrive.car import dbc_dict
from cereal import car
Ecu = car.CarParams.Ecu

class CAR:
  CROSSTREK_2020H = "SUBARU CROSSTREK LIMITED 2020 HYBRID"

FINGERPRINTS = {
  CAR.CROSSTREK_2020H: [{
    # Crosstrek 2020 Plugin Hybrid (revity)
    2: 8, 64: 8, 175: 8, 280: 8, 281: 8, 290: 8, 295: 8, 312: 8, 313: 8, 314: 8, 315: 8, 316: 8, 326: 8, 327: 3, 344: 8, 505: 8, 544: 8, 552: 8, 554: 8, 557: 8, 577: 8, 580: 8, 600: 8, 722: 8, 801: 8, 802: 8, 805: 8, 808: 8, 811: 8, 826: 8, 837: 8, 839: 8, 865: 8, 877: 8, 912: 8, 915: 8, 940: 8, 945: 8, 956: 8, 1031: 8, 1614: 8, 1617: 8, 1632: 8, 1657: 8, 1658: 8, 1677: 8, 1722: 8, 1750: 8, 1786: 5, 1787: 5, 1788: 8, 1813: 8, 1821: 8, 1840: 8, 1848: 8, 1924: 8, 1932: 8, 1952: 8, 1960: 8,
  }],
}

STEER_THRESHOLD = {
  CAR.CROSSTREK_2020H: 80,
}

ECU_FINGERPRINT = {
  Ecu.fwdCamera: [290, 356],   # steer torque cmd
}

DBC = {
  CAR.CROSSTREK_2020H: dbc_dict('subaru_global_2020', None),
}
