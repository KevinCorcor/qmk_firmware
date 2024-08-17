#include QMK_KEYBOARD_H
#include <tapDance/tapDance.h>
#include <homeRow/homeRow.h>
#include <macros/macros.h>
#include <combos/combos.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    TD(ESC_LCKS), KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,   /*|-------|*/   KC_Y,   KC_L,   KC_U,     KC_Y,     KC_QUOT,  _______,
    KC_TAB,       A_GUI,  R_ALT,  S_SFT,  T_CTL,  KC_G,   /*|-------|*/   KC_M,   N_CTL,  E_SFT,    I_ALT,    O_GUI,    _______,
    TD(VOLS_MAN), KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   /*|-------|*/   KC_K,   KC_H,   KC_COMM,  KC_DOT,   KC_SLSH,  _______,
                          _______,  TD(LAY_OHLD),  KC_BSPC, /*|---|*/ KC_SPC,   KC_ENT, _______
  ),
  [1] = LAYOUT_split_3x6_3(
    KC_GRV,   KC_EXLM,  KC_LCBR,  KC_RCBR,  _______,  KC_HASH,  /*|-------|*/   _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,     _______,
    KC_PIPE,  KC_AMPR,  KC_LPRN,  KC_RPRN,  KC_SCLN,  KC_BSLS,  /*|-------|*/   _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,   _______,
    KC_AT,    KC_DLR,   KC_LBRC,  KC_RBRC,  KC_UNDS,  _______,  /*|-------|*/   _______,  KC_UNDO,  _______,  _______,  C(KC_Z),    _______,
                                   _______,  _______,  KC_BSPC,   /*|---|*/   KC_SPC,   KC_ENT,   _______
  ),
  [2] = LAYOUT_split_3x6_3(
    KC_F1,    KC_F12,   KC_F3,    KC_F4,    KC_F5,    KC_F6,    /*|-------|*/   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    KC_DOT,   KC_0,     KC_1,     KC_2,     KC_3,     KC_4,     /*|-------|*/   KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_EQL,
    _______,  KC_FIND,  KC_CUT,   KC_COPY,  KC_PSTE,  _______,  /*|-------|*/   KC_CIRC,  KC_PPLS,  KC_PMNS,  KC_PAST,  KC_PSLS,  KC_PERC,
                                     _______,   _______,  KC_SPC, /*|---|*/  KC_ENT, _______, _______
  ),
  [3] = LAYOUT_split_3x6_3(
    QK_BOOT, KC_ESC, _______, _______, _______, _______,   /*|-------|*/   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   /*|-------|*/   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   /*|-------|*/   _______, _______, _______, _______, _______, _______,
                                   _______, _______,  KC_SPC, /*|---|*/   KC_ENT, _______, _______
  )
};
