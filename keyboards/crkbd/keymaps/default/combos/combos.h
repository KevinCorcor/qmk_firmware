enum combos {
  AB_ESC,
  JK_TAB,
  QW_SFT
};

const uint16_t PROGMEM ab_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {
  [AB_ESC] = COMBO(ab_combo, KC_ESC),
  [JK_TAB] = COMBO(jk_combo, KC_TAB),
  [QW_SFT] = COMBO(qw_combo, KC_LSFT)
};
