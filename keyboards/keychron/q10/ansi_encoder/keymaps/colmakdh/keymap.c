/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum custom_keycodes {
    EML_SIG = SAFE_RANGE,
    EML_LIVE,
    EML_G,
    XCASE
};

#include <tapDance/tapDance.h>
#include <homeRow/homeRow.h>
#include <casemodes/casemodes.h>
#include <combos/combos.h>


// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_89(
        KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,             _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,            _______,
        _______,  KC_GRV,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,               KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOTE, OSM(MOD_LSFT),_______,  _______,             _______,
        _______,  KC_EQUAL, A_GUI,    R_ALT,    S_SFT,    T_CTL,    KC_G,               KC_M,     N_CTL,    E_SFT,    I_ALT,    O_GUI,    KC_SCLN,                _______,             _______,
        _______,  KC_MINUS, KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     XCASE,    KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_BSLS,                _______,
        _______,  KC_LCTL,  KC_LOPT,            KC_TAB,  LT(1,KC_BSPC),  _______,                     LT(2,KC_SPC),             KC_ENT,                 _______,  _______,  _______),

    [MAC_FN] = LAYOUT_ansi_89(
        RM_TOGG,  _______,  _______,    _______,    _______,    _______,  _______,           _______,       _______,    _______,    _______,  _______,     _______,  _______,  _______,            _______,
        _______,  _______,  _______,    _______,    _______,    _______,  _______,           _______,       _______,    _______,    _______,  _______,     _______,  _______,  _______,            _______,
        _______,  KC_CIRC,  KC_EXLM,    KC_LCBR,    KC_RCBR,    _______,  KC_DLR,            TD(ESC_LCKS),  KC_HOME,    KC_PGDN,    KC_PGUP,  KC_END,      KC_DEL,   _______,  _______,            _______,
        _______,  KC_ASTR,  TD(AMPR_TD),TD(LPRN_TD),TD(RPRN_TD),SCLN_CTL, KC_AT,             _______,       LEFT_CTL,   DOWN_SFT,   UP_ALT,   RIGHT_GUI,   _______,            _______,            _______,
        _______,  KC_PERC,  KC_PIPE,    KC_LBRC,    KC_RBRC,    _______,  KC_HASH,  _______, TD(VOLS_MAN),  _______,    _______,    _______,  _______,     _______,            _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,                                      _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_89(
        KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,             _______,  KC_7,     KC_8,     KC_9,     _______,  _______,  _______,  _______,            _______,
        _______,  _______,  F5_GUI,   F6_ALT,   F7_SFT,   F8_CTL,   _______,             KC_DOT,   FOUR_CTL, FIVE_SFT, SIX_ALT,  ASTR_GUI, _______,            _______,            _______,
        _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,   _______,  KC_0,     KC_1,     KC_2,     KC_3,     KC_CIRC,  KC_PERC,            _______,
        _______,  _______,  _______,            _______,  _______,  _______,                     _______,             _______,                       _______,  _______,  _______),

    [WIN_FN] = LAYOUT_ansi_89(
        RM_TOGG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,   RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,             _______,  _______,  _______),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU) }
};
#endif // ENCODER_MAP_ENABLE

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