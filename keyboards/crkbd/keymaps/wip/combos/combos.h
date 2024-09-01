enum combos {
  ESC_LOCK,
  QP_EMLS,
  QW_UNDO,
  FP_REDO,
  ZX_COPY,
  XC_CUT,
  CD_PSTE
};

const uint16_t PROGMEM escq_combo[] = {TD(ESC_LCKS), KC_Q, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM qp_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
  [ESC_LOCK] = COMBO(escq_combo, LGUI(KC_L)),
  [QP_EMLS] = COMBO(qp_combo, EML_SIG),
  [QW_UNDO] = COMBO(qw_combo, C(KC_Z)),
  [FP_REDO] = COMBO(fp_combo, RCS(KC_Z)),
  [ZX_COPY] = COMBO(zx_combo, C(KC_C)),
  [XC_CUT] = COMBO(xc_combo, C(KC_X)),
  [CD_PSTE] = COMBO(cd_combo, C(KC_V)),
};
