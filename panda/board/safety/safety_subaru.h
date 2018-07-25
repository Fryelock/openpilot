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

static int subaru_fwd_hook(int bus_num, CAN_FIFOMailBox_TypeDef *to_fwd) {
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
