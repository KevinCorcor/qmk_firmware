enum combos {
  ESC_LOCK,
  QW_EMLS,
  QW_SFT
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM escq_combo[] = {TD(ESC_LCKS), KC_Q, COMBO_END};

combo_t key_combos[] = {
  [ESC_LOCK] = COMBO(escq_combo, LGUI(KC_L)),
  [QW_EMLS] = COMBO(qw_combo, EML_SIG),
};
