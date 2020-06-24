# flake8: noqa

from selfdrive.car import dbc_dict
from cereal import car
Ecu = car.CarParams.Ecu

class CAR:
  IMPREZA = "SUBARU IMPREZA LIMITED 2019"
  CROSSTREK_2020H = "SUBARU CROSSTREK LIMITED 2020 HYBRID"

FINGERPRINTS = {
  CAR.IMPREZA: [{
    2: 8, 64: 8, 65: 8, 72: 8, 73: 8, 280: 8, 281: 8, 290: 8, 312: 8, 313: 8, 314: 8, 315: 8, 316: 8, 326: 8, 544: 8, 545: 8, 546: 8, 552: 8, 554: 8, 557: 8, 576: 8, 577: 8, 722: 8, 801: 8, 802: 8, 805: 8, 808: 8, 816: 8, 826: 8, 837: 8, 838: 8, 839: 8, 842: 8, 912: 8, 915: 8, 940: 8, 1614: 8, 1617: 8, 1632: 8, 1650: 8, 1657: 8, 1658: 8, 1677: 8, 1697: 8, 1722: 8, 1743: 8, 1759: 8, 1786: 5, 1787: 5, 1788: 8, 1809: 8, 1813: 8, 1817: 8, 1821: 8, 1840: 8, 1848: 8, 1924: 8, 1932: 8, 1952: 8, 1960: 8
  },
  # Crosstrek 2018 (same platform as Impreza)
  {
    2: 8, 64: 8, 65: 8, 72: 8, 73: 8, 256: 8, 280: 8, 281: 8, 290: 8, 312: 8, 313: 8, 314: 8, 315: 8, 316: 8, 326: 8, 372: 8, 544: 8, 545: 8, 546: 8, 554: 8, 557: 8, 576: 8, 577: 8, 722: 8, 801: 8, 802: 8, 805: 8, 808: 8, 811: 8, 826: 8, 837: 8, 838: 8, 839: 8, 842: 8, 912: 8, 915: 8, 940: 8, 1614: 8, 1617: 8, 1632: 8, 1650: 8, 1657: 8, 1658: 8, 1677: 8, 1697: 8, 1759: 8, 1786: 5, 1787: 5, 1788: 8
  }],
  CAR.CROSSTREK_2020H: [{
    # Crosstrek 2020 Plugin Hybrid (revity)
    2: 8, 64: 8, 175: 8, 280: 8, 281: 8, 290: 8, 295: 8, 312: 8, 313: 8, 314: 8, 315: 8, 316: 8, 326: 8, 327: 3, 344: 8, 505: 8, 544: 8, 552: 8, 554: 8, 557: 8, 577: 8, 580: 8, 600: 8, 722: 8, 801: 8, 802: 8, 805: 8, 808: 8, 811: 8, 826: 8, 837: 8, 839: 8, 865: 8, 877: 8, 912: 8, 915: 8, 940: 8, 945: 8, 956: 8, 1031: 8, 1614: 8, 1617: 8, 1632: 8, 1657: 8, 1658: 8, 1677: 8, 1722: 8, 1750: 8, 1786: 5, 1787: 5, 1788: 8, 1813: 8, 1821: 8, 1840: 8, 1848: 8, 1924: 8, 1932: 8, 1952: 8, 1960: 8,
  }],
}

STEER_THRESHOLD = {
  CAR.IMPREZA: 80,
  CAR.CROSSTREK_2020H: 80,
}

ECU_FINGERPRINT = {
  Ecu.fwdCamera: [290, 356],   # steer torque cmd
}

DBC = {
  CAR.IMPREZA: dbc_dict('subaru_global_2017', None),
  CAR.CROSSTREK_2020H: dbc_dict('subaru_global_2020', None),
}
