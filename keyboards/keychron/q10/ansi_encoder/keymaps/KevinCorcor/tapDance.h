enum {
    A_GUI,
    R_ALT,
    S_SFT,
    T_CTL,
    O_GUI,
    I_ALT,
    E_SFT,
    N_CTL,

    AMPR_GUI,
    LPRN_ALT,
    RPRN_SFT,
    SCLN_CTL,
    END_GUI,
    RGHT_ALT,
    DOWN_SFT,
    LEFT_CTL
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(A_GUI):
        case TD(R_ALT):
        case TD(S_SFT):
        case TD(T_CTL):
        case TD(O_GUI):
        case TD(I_ALT):
        case TD(E_SFT):
        case TD(N_CTL):

        case TD(AMPR_GUI):
        case TD(LPRN_ALT):
        case TD(RPRN_SFT):
        case TD(SCLN_CTL):
        case TD(END_GUI):
        case TD(RGHT_ALT):
        case TD(DOWN_SFT):
        case TD(LEFT_CTL):

            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [A_GUI] = ACTION_TAP_DANCE_TAP_HOLD(KC_A, KC_LWIN),
    [R_ALT] = ACTION_TAP_DANCE_TAP_HOLD(KC_R, KC_LALT),
    [S_SFT] = ACTION_TAP_DANCE_TAP_HOLD(KC_S, KC_LSFT),
    [T_CTL] = ACTION_TAP_DANCE_TAP_HOLD(KC_T, KC_LCTL),
    [O_GUI] = ACTION_TAP_DANCE_TAP_HOLD(KC_O, KC_LWIN),
    [I_ALT] = ACTION_TAP_DANCE_TAP_HOLD(KC_I, KC_LALT),
    [E_SFT] = ACTION_TAP_DANCE_TAP_HOLD(KC_E, KC_LSFT),
    [N_CTL] = ACTION_TAP_DANCE_TAP_HOLD(KC_N, KC_LCTL),

    [AMPR_GUI] = ACTION_TAP_DANCE_TAP_HOLD(KC_AT, KC_LWIN),
    [LPRN_ALT] = ACTION_TAP_DANCE_TAP_HOLD(KC_LPRN, KC_LALT),
    [RPRN_SFT] = ACTION_TAP_DANCE_TAP_HOLD(KC_RPRN, KC_LSFT),
    [SCLN_CTL] = ACTION_TAP_DANCE_TAP_HOLD(KC_SCLN, KC_LCTL),
    [END_GUI] = ACTION_TAP_DANCE_TAP_HOLD(KC_END, KC_LWIN),
    [RGHT_ALT] = ACTION_TAP_DANCE_TAP_HOLD(KC_RIGHT, KC_LALT),
    [DOWN_SFT] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOWN, KC_LSFT),
    [LEFT_CTL] = ACTION_TAP_DANCE_TAP_HOLD(KC_LEFT, KC_LCTL),
};