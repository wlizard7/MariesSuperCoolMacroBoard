#include QMK_KEYBOARD_H

/* Keymap: 3x3 matrix */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
        { KC_1, KC_2, KC_MUTE },   // ROW0
        { KC_3, KC_4, KC_5 },      // ROW1
        { KC_6, KC_7, KC_8 }       // ROW2
    }
};

/* Encoder map: [layer][encoder][direction] */
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { {KC_VOLD, KC_VOLU} }  // CCW = volume down, CW = volume up
};

/* Use encoder_map automatically */
bool encoder_update_user(uint8_t index, bool clockwise) {
    return true;
}

/* Optional: process encoder press (mute) if assigned in keymap */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/* OLED display: simple smiley face example */
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_clear();
    oled_write_ln(PSTR("  ^   ^  "), false);
    oled_write_ln(PSTR("         "), false);
    oled_write_ln(PSTR("  \\___/  "), false);
    return false;
}
#endif