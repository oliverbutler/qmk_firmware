#include QMK_KEYBOARD_H

// Prevent normal rollover on alphas from accidentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold
#define TAPPING_FORCE_HOLD

#ifndef SOFLE_VAR_1
#define SOFLE_VAR_1 "default_value"
#endif

static const char sofle_var_1[] = SOFLE_VAR_1;

enum sofle_layers {
    _QWERTY,
    _NUM,
    _SYMBOLS,
    _BLANK,
};

enum custom_keycodes {
    KC_PASS_STR = SAFE_RANGE
};

#define KC_QWERTY PDF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬──────────┬──────────┬──────────┬──────────┬─────┐                                  ┌──────┬──────────┬──────────┬──────────┬──────────┬────┐
//    │  `   │    1     │    2     │    3     │    4     │  5  │                                  │  6   │    7     │    8     │    9     │    0     │ -  │
//    ├──────┼──────────┼──────────┼──────────┼──────────┼─────┤                                  ├──────┼──────────┼──────────┼──────────┼──────────┼────┤
//    │ tab  │    q     │    w     │    e     │    r     │  t  │                                  │  y   │    u     │    i     │    o     │    p     │ ]  │
//    ├──────┼──────────┼──────────┼──────────┼──────────┼─────┤                                  ├──────┼──────────┼──────────┼──────────┼──────────┼────┤
//    │ esc  │ CMD_T(a) │ ALT_T(s) │ SFT_T(d) │ CTL_T(f) │  g  │                                  │  h   │ CTL_T(j) │ SFT_T(k) │ ALT_T(l) │ CMD_T(;) │ '  │
//    ├──────┼──────────┼──────────┼──────────┼──────────┼─────┼──────────┐   ┌───────────────────┼──────┼──────────┼──────────┼──────────┼──────────┼────┤
//    │ lsft │    z     │    x     │    c     │    v     │  b  │   mute   │   │       mply        │  n   │    m     │    ,     │    .     │    /     │ no │
//    └──────┴──────────┼──────────┼──────────┼──────────┼─────┼──────────┤   ├───────────────────┼──────┼──────────┼──────────┼──────────┼──────────┴────┘
//                      │    no    │    no    │    no    │ spc │ MO(_NUM) │   │ LT(_SYMBOLS, ent) │ bspc │    no    │    no    │    no    │
//                      └──────────┴──────────┴──────────┴─────┴──────────┘   └───────────────────┴──────┴──────────┴──────────┴──────────┘
[_QWERTY] = LAYOUT(
  KC_GRV  , KC_1        , KC_2        , KC_3        , KC_4        , KC_5   ,                                       KC_6    , KC_7        , KC_8        , KC_9        , KC_0           , KC_MINS,
  KC_TAB  , KC_Q        , KC_W        , KC_E        , KC_R        , KC_T   ,                                       KC_Y    , KC_U        , KC_I        , KC_O        , KC_P           , KC_RBRC,
  KC_ESC  , CMD_T(KC_A) , ALT_T(KC_S) , SFT_T(KC_D) , CTL_T(KC_F) , KC_G   ,                                       KC_H    , CTL_T(KC_J) , SFT_T(KC_K) , ALT_T(KC_L) , CMD_T(KC_SCLN) , KC_QUOT,
  KC_LSFT , KC_Z        , KC_X        , KC_C        , KC_V        , KC_B   , KC_MUTE  ,     KC_MEDIA_PLAY_PAUSE  , KC_N    , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH        , XXXXXXX,
                          XXXXXXX     , XXXXXXX     , XXXXXXX     , KC_SPC , MO(_NUM) ,     LT(_SYMBOLS, KC_ENT) , KC_BSPC , XXXXXXX     , XXXXXXX     , XXXXXXX
),

//    ┌─────────┬─────┬─────┬─────┬─────┬─────┐                    ┌──────┬──────┬──────┬──────┬─────┬─────┐
//    │ QK_BOOT │ f1  │ f2  │ f3  │ f4  │ f5  │                    │  f6  │  f7  │  f8  │  f9  │ f10 │ f11 │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤                    ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │    0    │  1  │  2  │  3  │  4  │  5  │                    │  6   │  7   │  8   │  9   │  0  │ f12 │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤                    ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │         │     │     │     │     │     │                    │ left │ down │  up  │ rght │     │     │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┼──────────┐   ┌─────┼──────┼──────┼──────┼──────┼─────┼─────┤
//    │         │     │     │     │     │     │ pASS_STR │   │     │  [   │  ]   │ mprv │ mnxt │     │     │
//    └─────────┴─────┼─────┼─────┼─────┼─────┼──────────┤   ├─────┼──────┼──────┼──────┼──────┼─────┴─────┘
//                    │     │     │     │     │          │   │     │      │      │      │      │
//                    └─────┴─────┴─────┴─────┴──────────┘   └─────┴──────┴──────┴──────┴──────┘
[_NUM] = LAYOUT(
  QK_BOOT , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                             KC_F6   , KC_F7   , KC_F8               , KC_F9               , KC_F10  , KC_F11 ,
  KC_0    , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                             KC_6    , KC_7    , KC_8                , KC_9                , KC_0    , KC_F12 ,
  _______ , _______ , _______ , _______ , _______ , _______ ,                             KC_LEFT , KC_DOWN , KC_UP               , KC_RGHT             , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , KC_PASS_STR ,     _______ , KC_LBRC , KC_RBRC , KC_MEDIA_PREV_TRACK , KC_MEDIA_NEXT_TRACK , _______ , _______,
                      _______ , _______ , _______ , _______ , _______     ,     _______ , _______ , _______ , _______             , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │     │               │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  _  │  <  │  >  │  "  │  .  │               │  &  │  :  │  [  │  ]  │  @  │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  !  │  -  │  +  │  =  │  #  │               │  |  │  .  │  (  │  )  │  ?  │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │  /  │  *  │  \  │  %  │     │   │     │  ~  │  $  │  {  │  }  │     │     │
//    └─────┴─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┴─────┘
//                │     │     │     │     │     │   │     │     │     │     │     │
//                └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
[_SYMBOLS] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_UNDS , KC_LABK , KC_RABK , KC_DQUO , KC_DOT  ,                         KC_AMPR , KC_COLN , KC_LBRC , KC_RBRC , KC_AT   , _______,
  _______ , KC_EXLM , KC_MINS , KC_PLUS , KC_EQL  , KC_HASH ,                         KC_PIPE , KC_DOT  , KC_LPRN , KC_RPRN , KC_QUES , _______,
  _______ , _______ , KC_SLSH , KC_ASTR , KC_BSLS , KC_PERC , _______ ,     _______ , KC_TILD , KC_DLR  , KC_LCBR , KC_RCBR , _______ , _______,
                      _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
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
        case _NUM:
            oled_write_P(PSTR("NUM"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("SYMBOLS"), false);
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
    switch (keycode) {
        case KC_PASS_STR:
            if (record->event.pressed) {
                send_string(sofle_var_1);
                tap_code(KC_ENTER);
            }
            return false;
        default:
            return true;
    }
}
