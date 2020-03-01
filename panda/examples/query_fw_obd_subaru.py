#!/usr/bin/env python3
import time
import struct
from panda import Panda
from hexdump import hexdump
from panda.python.isotp import isotp_send, isotp_recv

if __name__ == "__main__":
  panda = Panda()
  panda.set_safety_mode(Panda.SAFETY_ELM327)
  panda.can_clear(0)

  # 09 02 = Get VIN
  isotp_send(panda, b"\x09\x02", 0x7df)
  ret = isotp_recv(panda, 0x7e8)
  hexdump(ret)
  print("VIN: %s" % "".join(map(chr, ret[2:])))

  # 09 04 = Get CAL ID
  isotp_send(panda, b"\x09\x04", 0x7df)
  ret = isotp_recv(panda, 0x7e8)
  hexdump(ret)
  print("0x7e8 CAL ID: %s" % "".join(map(chr, ret[2:])))

  # 09 04 = Get CAL ID
  isotp_send(panda, b"\x09\x04", 0x7df)
  ret = isotp_recv(panda, 0x7e9)
  hexdump(ret)
  print("0x7e9 CAL ID: %s" % "".join(map(chr, ret[2:])))

