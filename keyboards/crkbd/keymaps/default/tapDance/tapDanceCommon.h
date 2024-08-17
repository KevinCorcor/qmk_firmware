typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
td_state_t cur_dance(tap_dance_state_t *state);
void handle_state(td_state_t state, void (*registrar)(uint8_t), uint8_t key_taps[]);

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

void handle_state(td_state_t state, void (*registrar)(uint8_t), uint8_t key_taps[]) {
    switch (state) {
        case TD_SINGLE_TAP: registrar(key_taps[0]); break;
        case TD_SINGLE_HOLD: registrar(key_taps[1]); break;
        case TD_DOUBLE_TAP: registrar(key_taps[2]); break;
        case TD_DOUBLE_HOLD: registrar(key_taps[3]); break;
        case TD_TRIPLE_TAP: registrar(key_taps[4]); break;
        case TD_TRIPLE_HOLD: registrar(key_taps[5]); break;
        default: break;
    }
}
