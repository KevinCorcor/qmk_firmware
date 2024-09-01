#include <tapDance/tapDanceCustom.h>

// Tap dance enums
enum {
    ESC_LCKS,
    VOLS_MAN,
    OSM_LT1,
    // LAY_OHLD
};

uint8_t PROGMEM esclocks_key_taps[] = { KC_ESC, KC_NO, KC_CAPS, KC_NO, KC_NUM, KC_NO };
uint8_t PROGMEM sound_key_taps[] = { KC_MUTE, KC_VOLD, KC_NO, KC_VOLU, KC_NO, KC_NO };
// uint8_t PROGMEM layer_key_taps[] = { 0, 1, 0, 2, 0, 3 };


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

// void z_finished(tap_dance_state_t *state, void *user_data);
// void z_reset(tap_dance_state_t *state, void *user_data);
// void z_finished(tap_dance_state_t *state, void *user_data) {
//     xtap_state.state = cur_dance(state);
//     handle_state(xtap_state.state, layer_on, layer_key_taps);
// }
// void z_reset(tap_dance_state_t *state, void *user_data) {
//     handle_state(xtap_state.state, layer_off, layer_key_taps);
//     xtap_state.state = TD_NONE;
// }

void q_finished(tap_dance_state_t *state, void *user_data);
void q_reset(tap_dance_state_t *state, void *user_data);
void q_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    handle_custom_state_down(xtap_state.state);
}
void q_reset(tap_dance_state_t *state, void *user_data) {
    handle_custom_state_up(xtap_state.state);
    xtap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [ESC_LCKS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
    [VOLS_MAN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, y_finished, y_reset),
    // [LAY_OHLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, z_finished, z_reset)
    [OSM_LT1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_finished, q_reset)
};

