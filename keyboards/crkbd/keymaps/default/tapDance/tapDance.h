#include <tapDance/tapDanceCommon.h>

// Tap dance enums
enum {
    ESC_LCKS,
    VOLS_MAN
};

uint8_t PROGMEM esclocks_key_taps[] = { KC_ESC, KC_NO, KC_CAPS, KC_NO, KC_NUM, KC_NO };
uint8_t PROGMEM sound_key_taps[] = { KC_MUTE, KC_VOLD, KC_NO, KC_VOLU, KC_NO, KC_NO };

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);
void x_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    handle_state(xtap_state.state, register_code, esclocks_key_taps);
}
void x_reset(tap_dance_state_t *state, void *user_data) {
    handle_state(xtap_state.state, unregister_code, esclocks_key_taps);
    xtap_state.state = TD_NONE;
}

void y_finished(tap_dance_state_t *state, void *user_data);
void y_reset(tap_dance_state_t *state, void *user_data);
void y_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    handle_state(xtap_state.state, register_code, sound_key_taps);
}
void y_reset(tap_dance_state_t *state, void *user_data) {
    handle_state(xtap_state.state, unregister_code, sound_key_taps);
    xtap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [ESC_LCKS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
    [VOLS_MAN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, y_finished, y_reset)
};

