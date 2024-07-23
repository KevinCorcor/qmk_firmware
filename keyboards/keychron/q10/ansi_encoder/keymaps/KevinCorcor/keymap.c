#include QMK_KEYBOARD_H
#include <tapDance/tapDance.h>
#include <homeRowMod.h>

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

// clang-format off

enum layers{
    MAC_BASE,
    WIN_BASE,
    WIN_FN,
    WIN_FN2
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define WIN_FN2  3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_89(
        KC_MUTE,     KC_ESC,        KC_BRID,      KC_BRIU,      KC_NO,         KC_NO,        RGB_VAD,              RGB_VAI,      KC_MPRV,      KC_MPLY,       KC_MNXT,      KC_MUTE,       KC_VOLD,       KC_VOLU,      KC_INS,                    KC_DEL,
        _______,     KC_GRV,        KC_1,         KC_2,         KC_3,         KC_4,         KC_5,                  KC_6,         KC_7,         KC_8,          KC_9,         KC_0,          KC_MINS,       KC_EQL,       KC_BSPC,                   KC_PGUP,
        _______,     KC_TAB,        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                  KC_Y,         KC_U,         KC_I,          KC_O,         KC_P,          KC_LBRC,       KC_RBRC,      KC_BSLS,                   KC_PGDN,
        _______,     KC_CAPS,       KC_A,         KC_S,         KC_D,         KC_F,         KC_G,                  KC_H,         KC_J,         KC_K,          KC_L,         KC_SCLN,       KC_QUOT,                     KC_ENT,                    KC_HOME,
        _______,     KC_LSFT,       KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_B,    KC_N,         KC_M,         KC_COMM,       KC_DOT,       KC_SLSH,                                    KC_RSFT,      KC_UP,
        _______,     KC_LCTL,       KC_LWIN,                    KC_LALT,      KC_SPC,       KC_ENT,                KC_SPC,                     KC_RALT,                                                                 KC_LEFT,      KC_DOWN,     KC_RGHT
    ),
    [WIN_BASE] = LAYOUT_ansi_89(
        KC_MUTE,      KC_ESC,       KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,                 KC_F6,        KC_F7,        KC_F8,         KC_F9,        KC_F10,        KC_F11,        KC_F12,       KC_NO,                      KC_NO,
        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                 KC_NO,        KC_NO,        KC_NO,         KC_NO,        KC_NO,         KC_NO,         KC_NO,        KC_NO,                      KC_NO,
        KC_NO,        KC_NO,        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                  KC_J,         KC_L,         KC_U,          KC_Y,         KC_QUOT,       KC_NO,         KC_NO,        KC_NO,                      KC_NO,
        KC_NO,        KC_NO,        TD(A_0_GUI),  ALT_R,        SFT_S,        CTL_T2,       KC_G,                  KC_M,         CTL_N,        SFT_E,         ALT_I,        GUI_O,         KC_NO,                       KC_NO,                      KC_NO,
        KC_NO,        KC_NO,        KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,       KC_B,      KC_K,         KC_H,         KC_COMM,       KC_DOT,       KC_SCLN,                                    KC_NO,         KC_NO,
        KC_NO,        KC_NO,        KC_TAB,                     KC_TAB,       KC_BSPC,      LT(3,KC_ENT),          KC_SPC,                     QK_GESC,                                                                 KC_NO,         KC_NO,       KC_NO
    ),
    [WIN_FN] = LAYOUT_ansi_89(
        RGB_TOG,      KC_TRNS,      KC_BRID,      KC_BRIU,      LGUI(KC_TAB), LGUI(KC_E),   RGB_VAD,               RGB_VAI,      KC_MPRV,      KC_MPLY,       KC_MNXT,      KC_MUTE,       KC_VOLD,       KC_VOLU,      KC_TRNS,                    KC_TRNS,
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,               KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                    KC_TRNS,
        KC_TRNS,      KC_NUM ,      KC_DLR,       KC_LCBR,      KC_RCBR,      KC_MINS,      KC_EQL,                KC_TRNS,      S(KC_TAB),    KC_UP,         KC_TAB,       KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                    KC_TRNS,
        KC_NO,        KC_CAPS,      KC_AMPR,      KC_LPRN,      KC_RPRN,      KC_SCLN,      KC_QUOT,               KC_HOME,      KC_LEFT,      KC_DOWN,       KC_RGHT,      KC_END,        KC_TRNS,                     KC_TRNS,                    KC_TRNS,
        KC_TRNS,      KC_TRNS,      KC_EXLM,      KC_LBRC,      KC_RBRC,      KC_SLSH,      KC_BSLS,      KC_NO,   KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_NO,                                      KC_NO,         KC_NO,
        KC_NO,        KC_NO,        KC_NO,                      MO(4),        KC_TRNS,      KC_NO,                 KC_TRNS,                    KC_TRNS,                                                                 KC_NO,         KC_NO,       KC_NO
    ),
    [WIN_FN2] = LAYOUT_ansi_89(
        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                 KC_NO,        KC_NO,        KC_NO,         KC_NO,        KC_NO,         KC_NO,         KC_NO,        KC_NO,                      KC_NO,
        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                 KC_NO,        KC_PSLS,      KC_PAST,       KC_PERC,      KC_CIRC,       KC_NO,         KC_NO,        KC_NO,                      KC_NO,
        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                 KC_PMNS,      KC_P7,        KC_P8,         KC_P9,        KC_NO,         KC_NO,         KC_NO,        KC_NO,                      KC_NO,
        KC_NO,        KC_NO,        KC_NO,        C(KC_X),      C(KC_C),      C(KC_V),      C(KC_F),               KC_PPLS,      KC_P4,        KC_P5,         KC_P6,        KC_NO,         KC_NO,                       KC_NO,                      KC_NO,
        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_P0,   KC_P0,        KC_P1,        KC_P2,         KC_P3,        KC_NO,                                      KC_NO,         KC_NO,
        KC_NO,        KC_NO,        KC_NO,                      KC_TRNS,      KC_TRNS,      KC_NO,                 KC_TRNS,                    KC_EQL,                                                                  KC_NO,         KC_NO,       KC_NO
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD,    KC_VOLU) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_FN2]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif // ENCODER_MAP_ENABLE
