#include <tapDance/tapDanceCustom.h>

uint8_t PROGMEM esclocks_key_taps[] = { KC_ESC, KC_NO, KC_CAPS, KC_NO, KC_NUM, KC_NO };
uint8_t PROGMEM sound_key_taps[] = { KC_MUTE, KC_VOLD, KC_NO, KC_VOLU, KC_NO, KC_NO };
uint16_t PROGMEM LPRN_key_taps[] = { S(KC_9), KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO };
uint16_t PROGMEM RPRN_key_taps[] = { S(KC_0), KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO };
uint16_t PROGMEM AMPR_key_taps[] = { S(KC_7), KC_LGUI, KC_NO, KC_NO, KC_NO, KC_NO };
// uint8_t PROGMEM layer_key_taps[] = { 0, 1, 0, 2, 0, 3 };
//TODO: generalise this
void w_finished(tap_dance_state_t *state, void *user_data);
void w_reset(tap_dance_state_t *state, void *user_data);
void w_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    handle_state16(xtap_state.state, register_code16, AMPR_key_taps);
}
void w_reset(tap_dance_state_t *state, void *user_data) {
    handle_state16(xtap_state.state, unregister_code16, AMPR_key_taps);
    xtap_state.state = TD_NONE;
}

void v_finished(tap_dance_state_t *state, void *user_data);
void v_reset(tap_dance_state_t *state, void *user_data);
void v_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    handle_state16(xtap_state.state, register_code16, RPRN_key_taps);
}
void v_reset(tap_dance_state_t *state, void *user_data) {
    handle_state16(xtap_state.state, unregister_code16, RPRN_key_taps);
    xtap_state.state = TD_NONE;
}

void z_finished(tap_dance_state_t *state, void *user_data);
void z_reset(tap_dance_state_t *state, void *user_data);
void z_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    handle_state16(xtap_state.state, register_code16, LPRN_key_taps);
}
void z_reset(tap_dance_state_t *state, void *user_data) {
    handle_state16(xtap_state.state, unregister_code16, LPRN_key_taps);
    xtap_state.state = TD_NONE;
}

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
    [LPRN_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, z_finished, z_reset),
    [RPRN_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, v_finished, v_reset),
    [AMPR_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, w_finished, w_reset),
    [OSM_LT1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_finished, q_reset)
};

