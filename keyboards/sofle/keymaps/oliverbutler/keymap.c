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
//    ┌──────┬───────────────┬────┬──────┬──────┬─────┐                       ┌──────┬──────┬──────┬──────┬──────────┬──────────┐
//    │  `   │       1       │ 2  │  3   │  4   │  5  │                       │  6   │  7   │  8   │  9   │    0     │    -     │
//    ├──────┼───────────────┼────┼──────┼──────┼─────┤                       ├──────┼──────┼──────┼──────┼──────────┼──────────┤
//    │ esc  │       q       │ w  │  e   │  r   │  t  │                       │  y   │  u   │  i   │  o   │    p     │    ]     │
//    ├──────┼───────────────┼────┼──────┼──────┼─────┤                       ├──────┼──────┼──────┼──────┼──────────┼──────────┤
//    │ lsft │       a       │ s  │  d   │  f   │  g  │                       │  h   │  j   │  k   │  l   │ CTL_T(;) │ SFT_T(') │
//    ├──────┼───────────────┼────┼──────┼──────┼─────┼────────────┐   ┌──────┼──────┼──────┼──────┼──────┼──────────┼──────────┤
//    │ lctl │ LT(_ARROW, z) │ x  │  c   │  v   │  b  │    mute    │   │ mply │  n   │  m   │  ,   │  .   │    /     │   rsft   │
//    └──────┴───────────────┼────┼──────┼──────┼─────┼────────────┤   ├──────┼──────┼──────┼──────┼──────┼──────────┴──────────┘
//                           │ no │ lalt │ lgui │ spc │ MO(_LOWER) │   │ ent  │ bspc │ rgui │ ralt │ rgui │
//                           └────┴──────┴──────┴─────┴────────────┘   └──────┴──────┴──────┴──────┴──────┘
[_QWERTY] = LAYOUT(
  KC_GRV  , KC_1             , KC_2    , KC_3    , KC_4    , KC_5   ,                                        KC_6    , KC_7    , KC_8    , KC_9    , KC_0           , KC_MINS       ,
  KC_ESC  , KC_Q             , KC_W    , KC_E    , KC_R    , KC_T   ,                                        KC_Y    , KC_U    , KC_I    , KC_O    , KC_P           , KC_RBRC       ,
  KC_LSFT , KC_A             , KC_S    , KC_D    , KC_F    , KC_G   ,                                        KC_H    , KC_J    , KC_K    , KC_L    , CTL_T(KC_SCLN) , SFT_T(KC_QUOT),
  KC_LCTL , LT(_ARROW, KC_Z) , KC_X    , KC_C    , KC_V    , KC_B   , KC_MUTE    ,     KC_MEDIA_PLAY_PAUSE , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH        , KC_RSFT       ,
                               XXXXXXX , KC_LALT , KC_LCMD , KC_SPC , MO(_LOWER) ,     KC_ENT              , KC_BSPC , KC_RCMD , KC_RALT , KC_RGUI
),

//    ┌─────┬────┬─────┬─────┬─────┬─────┐               ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │ f1 │ f2  │ f3  │ f4  │ f5  │               │ f6  │ f7  │ f8  │ f9  │ f10 │ f11 │
//    ├─────┼────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │ tab │ 1  │  2  │  3  │  4  │  5  │               │  6  │  7  │  8  │  9  │  0  │ f12 │
//    ├─────┼────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │ !  │  @  │  #  │  $  │  %  │               │  ^  │  &  │  *  │  (  │  )  │  |  │
//    ├─────┼────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │ =  │  -  │  +  │  {  │  }  │     │   │     │  [  │  ]  │  ;  │  :  │  \  │     │
//    └─────┴────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┴─────┘
//               │     │     │     │     │     │   │     │     │     │     │     │
//               └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
[_LOWER] = LAYOUT(
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                         KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11 ,
  KC_TAB  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_F12 ,
  _______ , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,                         KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_PIPE,
  _______ , KC_EQL  , KC_MINS , KC_PLUS , KC_LCBR , KC_RCBR , _______ ,     _______ , KC_LBRC , KC_RBRC , KC_SCLN , KC_COLN , KC_BSLS , _______,
                      _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌─────────┬─────┬─────┬─────┬─────┬─────┐               ┌──────┬──────┬──────┬──────┬─────┬─────┐
//    │ QK_BOOT │     │     │     │     │     │               │      │      │      │      │     │     │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤               ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │ CG_TOGG │     │     │     │     │     │               │      │      │      │      │     │     │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤               ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │         │     │     │     │     │     │               │ left │ down │  up  │ rght │  -  │     │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼──────┼──────┼──────┼──────┼─────┼─────┤
//    │         │     │     │     │     │     │     │   │     │  [   │  ]   │ mnxt │ mprv │     │     │
//    └─────────┴─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼─────┴─────┘
//                    │     │     │     │     │     │   │     │      │      │      │      │
//                    └─────┴─────┴─────┴─────┴─────┘   └─────┴──────┴──────┴──────┴──────┘
[_ARROW] = LAYOUT(
  QK_BOOT , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______             , _______             , _______ , _______,
  CG_TOGG , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______             , _______             , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ ,                         KC_LEFT , KC_DOWN , KC_UP               , KC_RGHT             , KC_MINS , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,     _______ , KC_LBRC , KC_RBRC , KC_MEDIA_NEXT_TRACK , KC_MEDIA_PREV_TRACK , _______ , _______,
                      _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______             , _______
)
};


// Low poly leaf logo - 32x32 pixels
static const char PROGMEM leaf_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x80, 0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0x70, 0x38,
    0x18, 0x1C, 0x0C, 0x06, 0x03, 0x03, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE,
    0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F,
    0x1F, 0x3F, 0x7F, 0xFF, 0xFE, 0xFC, 0xF8, 0xF0,
    0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static void render_layer_state(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("Layer"), false);
    oled_set_cursor(0, 1);
    oled_write_P(PSTR("-----"), false);
    oled_set_cursor(0, 2);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("BASE "), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ  "), false);
            break;
        case _ARROW:
            oled_write_P(PSTR("ARROW"), false);
            break;
        default:
            oled_write_P(PSTR("?????"), false);
    }
}

static void render_leaf_logo(void) {
    oled_write_P(PSTR("Sofle"), false);
    oled_set_cursor(0, 1);
    oled_write_raw_P(leaf_logo, sizeof(leaf_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Left side - Layer status
        render_layer_state();
    } else {
        // Right side - Logo
        render_leaf_logo();
    }
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
