// Left-hand home row mods
    #define A_GUI        LGUI_T(KC_A)
    #define R_ALT        LALT_T(KC_R)
    #define S_SFT        LSFT_T(KC_S)
    #define T_CTL        LCTL_T(KC_T)

// Right-hand home row mods
    #define N_CTL        RCTL_T(KC_N)
    #define E_SFT        RSFT_T(KC_E)
    #define I_ALT        LALT_T(KC_I)
    #define O_GUI        RGUI_T(KC_O)

// Left-hand home row mods
    // #define AMPR_GUI     LGUI_T(KC_AMPR)
    #define SCLN_CTL     LCTL_T(KC_SCLN)

// Right-hand home row mods
    #define LEFT_CTL     RCTL_T(KC_LEFT)
    #define DOWN_SFT     RSFT_T(KC_DOWN)
    #define UP_ALT       LALT_T(KC_UP)
    #define RIGHT_GUI    RGUI_T(KC_RIGHT)

// Left-hand home row mods
    #define F5_GUI       LGUI_T(KC_F5)
    #define F6_ALT       LALT_T(KC_F6)
    #define F7_SFT       LSFT_T(KC_F7)
    #define F8_CTL       LCTL_T(KC_F8)

// Right-hand home row mods
    #define FOUR_CTL     RCTL_T(KC_4)
    #define FIVE_SFT     RSFT_T(KC_5)
    #define SIX_ALT      LALT_T(KC_6)
    #define ASTR_GUI     RGUI_T(KC_ASTR)

// enum custom_keycodes2 {
//     LPRN_ALT = SAFE_RANGE,
//     RPRN_SFT
// };

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LPRN_ALT:
//             if (record->event.pressed) {
//                 if (record->tap.count > 0) {
//                     // Tap
//                     register_code(KC_LSHIFT);
//                     register_code(KC_9);
//                     unregister_code(KC_9);
//                     unregister_code(KC_LSHIFT);
//                 } else {
//                     // Hold
//                     register_mods(MOD_BIT(KC_LALT));
//                 }
//             } else {
//                 unregister_mods(MOD_BIT(KC_LALT));
//             }
        //     return false;
        // case RPRN_SFT:
        //     if (record->event.pressed) {
        //         if (record->tap.count > 0) {
                    // Tap
                    // register_code(KC_LSHIFT);
//                     register_code(KC_0);
//                     unregister_code(KC_0);
//                     unregister_code(KC_LSHIFT);
//                 } else {
//                     // Hold
//                     register_mods(MOD_BIT(KC_LSFT));
//                 }
//             } else {
//                 unregister_mods(MOD_BIT(KC_LSFT));
//             }
//             return false;
//     }
//     return true;
// }
//
