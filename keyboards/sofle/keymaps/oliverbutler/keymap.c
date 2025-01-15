#include QMK_KEYBOARD_H

// Configure TAPPING_TERM
#define TAPPING_TERM 200
// Prevent normal rollover on alphas from accidentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold
#define TAPPING_FORCE_HOLD


enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARROW,
};

enum custom_keycodes {
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

#define KC_QWERTY PDF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
   KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_RBRC,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    LCTL_T(KC_SCLN),  KC_QUOT,
  KC_LCTL,  LT(_ARROW, KC_Z),   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,  XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
        KC_LGUI, KC_LALT, KC_LCMD, KC_SPC, MO(_LOWER),  KC_ENT,  KC_BSPC, KC_RCTL, KC_RALT, KC_RGUI
),
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
[_ARROW] = LAYOUT(
      QK_BOOT, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//    boot
      CG_TOGG, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//    os/swap
      _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
//                                                                                left     down     up      right
      _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//
                        _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
//

),
};


static void render_status(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("Sofle\n"), false);

    // Layer status
    oled_set_cursor(2, 0);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("NORMAL\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("ARROW\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    }
    return false;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
