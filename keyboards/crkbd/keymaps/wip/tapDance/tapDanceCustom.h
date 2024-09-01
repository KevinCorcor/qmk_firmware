#include <tapDance/tapDanceCommon.h>

void handle_custom_state_down(td_state_t state);
void handle_custom_state_down(td_state_t state) {
    switch (state) {
        case TD_SINGLE_TAP: set_oneshot_mods(MOD_LSFT); break;
        case TD_SINGLE_HOLD: layer_on(1); break;
        case TD_DOUBLE_TAP: layer_invert(2); break;
        case TD_DOUBLE_HOLD:
        case TD_TRIPLE_TAP:
        case TD_TRIPLE_HOLD:
        default: break;
    }
}

void handle_custom_state_up(td_state_t state);
void handle_custom_state_up(td_state_t state) {
    switch (state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: layer_off(1); break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD:
        case TD_TRIPLE_TAP:
        case TD_TRIPLE_HOLD:
        default: break;
    }
}
