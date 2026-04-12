#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: QWERTY
    [0] = {
        {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC},
        {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS},
        {KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT},
        {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,   KC_NO,   KC_RSFT},
        {KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_RALT, KC_RGUI, KC_NO,   KC_NO,   KC_NO,   KC_RCTL},
    },

    // Layer 1: Function/Media
    [1] = {
        {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL},
        {_______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______},
        {_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______},
        {_______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    },
};

// Encoder map: rotate to change volume, press to mute
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif

// OLED display
#ifdef OLED_ENABLE
static void render_status(void) {
    // Keyboard name
    oled_write_P(PSTR("60% KB | "), false);

    // Current layer
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("QWERTY  "), false);
            break;
        case 1:
            oled_write_P(PSTR("FN/MEDIA"), false);
            break;
        default:
            oled_write_P(PSTR("UNKNOWN "), false);
            break;
    }

    oled_write_P(PSTR("\n"), false);

    // Modifier indicators
    uint8_t mods = get_mods() | get_oneshot_mods();
    oled_write_P(mods & MOD_MASK_SHIFT ? PSTR("SFT ") : PSTR("    "), false);
    oled_write_P(mods & MOD_MASK_CTRL  ? PSTR("CTL ") : PSTR("    "), false);
    oled_write_P(mods & MOD_MASK_ALT   ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_P(mods & MOD_MASK_GUI   ? PSTR("GUI ") : PSTR("    "), false);

    oled_write_P(PSTR("\n"), false);

    // Lock key indicators
    led_t leds = host_keyboard_led_state();
    oled_write_P(leds.caps_lock   ? PSTR("CAPS ") : PSTR("     "), false);
    oled_write_P(leds.num_lock    ? PSTR("NUM  ") : PSTR("     "), false);
    oled_write_P(leds.scroll_lock ? PSTR("SCR  ") : PSTR("     "), false);
}

bool oled_task_user(void) {
    render_status();
    return false;
}
#endif
