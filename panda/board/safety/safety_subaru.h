void subaru_rx_hook(CAN_FIFOMailBox_TypeDef *to_push) {}

int subaru_ign_hook() {
  return -1; // use GPIO to determine ignition
}

// FIXME
// *** all output safety mode ***

static void subaru_init(int16_t param) {
  controls_allowed = 1;
}

static int subaru_tx_hook(CAN_FIFOMailBox_TypeDef *to_send) {
  return true;
}

static int subaru_tx_lin_hook(int lin_num, uint8_t *data, int len) {
  return true;
}

// do not forward
/*
static int subaru_fwd_hook(int bus_num, CAN_FIFOMailBox_TypeDef *to_fwd) {
  return -1;
}
*/

// toyota version with magical return value
/*
static int subaru_fwd_hook(int bus_num, CAN_FIFOMailBox_TypeDef *to_fwd) {

  // forward es to car and viceversa, filter out es_lkas cmd
  if ((bus_num == 0 || bus_num == 1)) {
    int addr = to_fwd->RIR>>21;
    bool is_lkas_msg = (addr == 0x122) && bus_num == 1;
    return is_lkas_msg ? -1 : (uint8_t)(~bus_num & 0x2);
  }
  return -1;
}
*/

// tesla version adaptation
static int subaru_fwd_hook(int bus_num, CAN_FIFOMailBox_TypeDef *to_fwd) {
  
  // convert little endian to hex?
  int32_t addr = to_fwd->RIR >> 21;
  
  // debug console output
  //puts("RIR: ");
  //puth(to_fwd->RIR);
  //puts("\n");
  //puts("addr: ");
  //puth(addr);
  //puts("\n");

  // forward CAN 0 > 1
  if (bus_num == 0) {
    return 1; // ES CAN
  }
  // forward CAN 1 > 0, except ES_LKAS
  else if (bus_num == 1) {
    
    // subaru global
    if (addr == 0x122) {
      return -1;
    }
    // outback 2015
    else if (addr == 0x164) {
      return -1;
    }

    return 0; // Main CAN
  }

  // fallback to do not forward
  return -1;
}

const safety_hooks subaru_hooks = {
  .init = subaru_init,
  .rx = subaru_rx_hook,
  .tx = subaru_tx_hook,
  .tx_lin = subaru_tx_lin_hook,
  .ignition = subaru_ign_hook,
  .fwd = subaru_fwd_hook,
};
