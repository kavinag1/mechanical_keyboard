#include QMK_KEYBOARD_H

/* 
 * 60% Mechanical Keyboard - Default Keymap
 * 5 rows x 14 columns
 * Based on actual PCB wiring layout
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Layer 0: Default QWERTY Layout
     * Row 0: Esc 1 2 3 4 5 6 7 8 9 0 - = [BackSpace]
     * Row 1: Tab Q W E R T Y U I O P [ ] \
     * Row 2: Caps A S D F G H J K L ; '   [Return]
     * Row 3: Shift Z X C V B N M , . / [Shift]
     * Row 4: Ctrl Win Alt [Space] Alt Win Menu Ctrl
     */
    [0] = {
        {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC},
        {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS},
        {KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT},
        {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,   KC_NO,   KC_RSFT},
        {KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_RALT, KC_RGUI, KC_NO,   KC_NO,   KC_NO,   KC_RCTL},
    },

    /*
     * Layer 1: Function/Media Layer
     * Row 0: ` F1 F2 F3 F4 F5 F6 F7 F8 F9 F10 F11 F12 [Delete]
     * Row 1: --- Home Up End PgUp --- --- --- --- PrtSc ScrLk Pause --- ---
     * Row 2: --- Left Down Right PgDn --- Left Down Up Right --- --- ---
     * Row 3: --- VolDn VolUp Mute --- --- --- --- --- --- --- --- ---
     * Row 4: --- --- --- [Space] --- --- --- --- --- --- --- ---
     */
    [1] = {
        {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL},
        {_______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______},
        {_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______},
        {_______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    },
};

/* Optional: Add layer indicators with LEDs */
/* 
layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}
*/

/* Optional: Process custom keycodes */
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_EXAMPLE:
            if (record->event.pressed) {
                // Code for key press
            } else {
                // Code for key release
            }
            return false;
        case KC_SOMETHING:
            if (record->event.pressed) {
                SEND_STRING("Hello, World!");
            }
            return false;
    }
    return true;
}
*/

/* Optional: Tap dance definitions */
/*
enum {
    TD_ESC_CAPS = 0,
};

// Tap once = ESC, tap twice = CAPS LOCK
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};
*/
