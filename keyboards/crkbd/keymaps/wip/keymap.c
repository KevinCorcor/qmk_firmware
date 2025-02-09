#include QMK_KEYBOARD_H

enum custom_keycodes {
    EML_SIG = SAFE_RANGE,
    EML_LIVE,
    EML_G,
    XCASE,
    ESC_LCKS,
    VOLS_MAN,
    AMPR_TD,
    RPRN_TD,
    LPRN_TD
};

#include <tapDance/tapDance.h>
#include <homeRow/homeRow.h>
#include <macros/macros.h>
#include <casemodes/casemodes.h>
#include <combos/combos.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    KC_GRV,     KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,   /*|-------|*/   KC_J,   KC_L,   KC_U,     KC_Y,     KC_QUOTE,   OSM(MOD_LSFT),
    KC_EQUAL,   A_GUI,  R_ALT,  S_SFT,  T_CTL,  KC_G,   /*|-------|*/   KC_M,   N_CTL,  E_SFT,    I_ALT,    O_GUI,      KC_SCLN,
    KC_MINUS,   KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   /*|-------|*/   KC_K,   KC_H,   KC_COMM,  KC_DOT,   KC_SLSH,    KC_BSLS,
                        _______,  KC_TAB,  LT(1,KC_BSPC), /*|---|*/ LT(2,KC_SPC), KC_ENT, XCASE
  ),
  [1] = LAYOUT_split_3x6_3(
    KC_CIRC,    KC_EXLM,        KC_LCBR,        KC_RCBR,        _______,    KC_DLR,     /*|-------|*/   TD(ESC_LCKS),   KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_DEL,
    KC_ASTR,    TD(AMPR_TD),    TD(LPRN_TD),    TD(RPRN_TD),    SCLN_CTL,   KC_AT,      /*|-------|*/   _______,        LEFT_CTL,   DOWN_SFT,   UP_ALT,     RIGHT_GUI,  _______,
    KC_PERC,    KC_PIPE,        KC_LBRC,        KC_RBRC,        _______,    KC_HASH,    /*|-------|*/   TD(VOLS_MAN),   _______,    _______,    _______,    _______,    _______,
                                                           _______,  _______,  _______,   /*|---|*/   _______,   _______,   _______
  ),
  [2] = LAYOUT_split_3x6_3(
    _______,    KC_F9,  KC_F10, KC_F11, KC_F12, _______,    /*|-------|*/   _______,    KC_7,       KC_8,       KC_9,       _______,    _______,
    _______,    F5_GUI, F6_ALT, F7_SFT, F8_CTL, _______,    /*|-------|*/   KC_DOT,     FOUR_CTL,   FIVE_SFT,   SIX_ALT,    ASTR_GUI,   _______,
    _______,    KC_F1,  KC_F2,  KC_F3,  KC_F4,  _______,    /*|-------|*/   KC_0,       KC_1,       KC_2,       KC_3,       KC_CIRC,    KC_PERC,
                                _______,   MO(3),  _______, /*|---|*/  _______, _______, _______
  ),
  [3] = LAYOUT_split_3x6_3(
    QK_BOOT, _______, _______, _______, _______, _______,   /*|-------|*/   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   /*|-------|*/   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   /*|-------|*/   _______, _______, _______, _______, _______, _______,
                                   _______, _______,  _______, /*|---|*/   _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // uint8_t current_layer = get_highest_layer(layer_state);  // Get current active layer
    // uprintf("2. Keycode: %u, Layer: %d, Tap Count: %d, Pressed: %d, Interupted: %d, tappedKey:\n", keycode, current_layer, record->tap.count, record->event.pressed, record->tap.interrupted);
    if (!process_case_modes(keycode, record))
        return false;

    switch (keycode) {
        case XCASE:
            if (record->event.pressed)
                enable_xcase();

            return false;

        // macros
        case EML_SIG:
            if (record->event.pressed)
                SEND_STRING("kevin.corcoran@sig.com");
            break;
        case EML_LIVE:
            if (record->event.pressed)
                SEND_STRING("corkey@live.ie");
            break;
        case EML_G:
            if (record->event.pressed)
                SEND_STRING("corkeyin@gmail.com");
            break;
    }

    return true;
}
