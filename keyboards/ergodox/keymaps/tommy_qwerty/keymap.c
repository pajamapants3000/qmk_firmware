/* tommy_qwerty
 * keymap for the ergodox ez
 * Currently, none of the KC_MEDIA_* keys seem to do anything
 * Also, KC_WWW_FAVORITES and KC_ACL* don't seem to do anything either
 *
 * There is probably a lot more I can do with this, but it's a nice start!
 */

#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |WWW-Bk|           |WWW-Fw|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |WWW-Hm|           |WWW-Rf|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | S-Tab  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |  '     |
 * |--------+------+------+------+------+------| C-F12|           |File-M|------+------+------+------+------+--------|
 * | LS/PO  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RS/PC  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Esc  | Grv  | App  | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  | TO-2 |       | TO-1 | Enter  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |2/Home|       | End  |        |      |
 *                                 | BkSp | RCtrl|------|       |------| LGui   | Space|
 *                                 |      |      | LAlt |       | MO-1 |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_WWW_BACK,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_WWW_HOME,
        LSFT(KC_TAB),   KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSPO,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   RCTL(KC_F12),
        KC_ESCAPE,      KC_GRAVE,     KC_APPLICATION, KC_LEFT,KC_RIGHT,
                                              KC_DELETE,  TO(2),
                                                          LT(2,KC_HOME),
                                              KC_BSPC,    KC_RCTRL, KC_LALT,
        // right hand
             KC_WWW_FORWARD,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,     KC_MINUS,
             KC_WWW_REFRESH,      KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_BSLS,
                                  KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,
             KC_MY_COMPUTER,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RSPC,
                                  KC_DOWN,KC_UP,KC_LBRC,KC_RBRC,KC_NO,
             TO(1),     KC_ENT,
             KC_END,
             MO(1),     KC_LGUI, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Search |  F1  |  F2  |  F3  |  F4  |  F5  |TRANS |           |TRANS |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | C-T    |   !  |   @  |   {  |   }  |   |  |      |           |      | PgUp |   7  |   8  |   9  |   -  |   F12  |
 * |--------+------+------+------+------+------|TRANS |           |TRANS |------+------+------+------+------+--------|
 * | C-D    |   #  |   &  |   (  |   )  |   %  |------|           |------| PgDn |   4  |   5  |   6  |   +  |   /    |
 * |--------+------+------+------+------+------|WWW-Fv|           |Search|------+------+------+------+------+--------|
 * | Caps   |   `  |   ~  |   [  |   ]  |   ^  |      |           |      |   $  |   1  |   2  |   3  |   *  |  NUM   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |C-A-1 |C-A-2 |C-A-3 |C-A-4 |C-A-5 |                                       |   0  |   .  |   =  | Enter| TO-L0|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |TRANS | TO-0 |       | TO-2 |TRANS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | End  |      |      |
 *                                 |TRANS |TRANS |------|       |------|TRANS |TRANS |
 *                                 |      |      |TRANS |       |TRANS |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_WWW_SEARCH,     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       RCTL(KC_T),        KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       RCTL(KC_D),        KC_HASH,KC_AMPR,KC_LPRN,KC_RPRN,KC_PERC,
       KC_CAPSLOCK,       KC_GRV, KC_TILD,KC_LBRC,KC_RBRC,KC_CIRC,KC_WWW_FAVORITES,
       LALT(RCTL(KC_1)),  LALT(RCTL(KC_2)),   LALT(RCTL(KC_3)),   LALT(RCTL(KC_4)),   LALT(RCTL(KC_5)),
                                       KC_TRNS, TO(0),
                                                KC_HOME,
                               KC_TRNS,KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,       KC_F6,  KC_F7,    KC_F8,      KC_F9,      KC_F10,         KC_F11,
       KC_TRNS,       KC_UP,  KC_KP_7,  KC_KP_8,    KC_KP_9,    KC_KP_MINUS,    KC_F12,
                      KC_DOWN,KC_KP_4,  KC_KP_5,    KC_KP_6,    KC_KP_PLUS,     KC_KP_SLASH,
       KC_WWW_SEARCH, KC_DLR, KC_KP_1,  KC_KP_2,    KC_KP_3,    KC_KP_ASTERISK, KC_NUMLOCK,
                              KC_KP_0,  KC_KP_DOT,  KC_EQUAL,   KC_KP_ENTER,    TO(0),
       TO(2), KC_TRNS,
       KC_END,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Win-L  | ???  | Cut  | Copy | Paste| Find |TRANS |           |TRANS | Prev | Rew  | Play | FF   | Next | Stop   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ?Power | ???  | Undo | WlUp | C-Y  | C-=  |TRANS |           |TRANS | C-Lft| LClk | MsUp | RClk | C-Rt | Vol-Up |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Reset  |SysRq | WlLt | WlDn | WlRt | C--  |------|           |------| Left | MsLt | MsDn | MsRt | Right| Vol-Dn |
 * |--------+------+------+------+------+------| CALC |           | MAIL |------+------+------+------+------+--------|
 * | Scroll | VERSN| Acc0 | Acc1 | Acc2 | C-0  |      |           |      | S-Lft| MB4  | MdClk| MB5  | S-Rt | Mute   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |C-A-6 |C-A-7 |C-A-8 |C-A-9 |C-A-0 |                                       | ???? | ???  |  ??? | ???  | TO-L0|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |TRANS | TO-1 |       | TO-0 |TRANS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |TRANS |       |TRANS |      |      |
 *                                 |TRANS |TRANS |------|       |------|TRANS |TRANS |
 *                                 |      |      |TRANS |       | ???? |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       LGUI(KC_L), KC_NO, KC_CUT, KC_COPY, KC_PASTE, KC_FIND, KC_TRNS,
       KC_POWER, KC_NO, KC_UNDO, KC_MS_WH_UP, RCTL(KC_Y), RCTL(KC_EQUAL), KC_TRNS,
       RESET, KC_PSCREEN, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, RCTL(KC_MINUS),
       KC_SLCK, M(0), KC_ACL0, KC_ACL1, KC_ACL2, RCTL(KC_0), KC_CALCULATOR,
       LALT(RCTL(KC_6)),  LALT(RCTL(KC_7)),   LALT(RCTL(KC_8)),   LALT(RCTL(KC_9)),   LALT(RCTL(KC_0)),
                                           KC_TRNS, TO(1),
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_MEDIA_PREV_TRACK, KC_MEDIA_REWIND, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD, KC_MEDIA_NEXT_TRACK, KC_MEDIA_STOP,
       KC_TRNS,  RCTL(KC_LEFT), KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, RCTL(KC_RIGHT), KC_AUDIO_VOL_UP,
                 KC_LEFT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,KC_RIGHT, KC_AUDIO_VOL_DOWN,
       KC_MAIL,  LSFT(KC_LEFT), KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN5, LSFT(KC_RIGHT), KC_AUDIO_MUTE,
                          KC_NO, KC_NO,  KC_NO, KC_NO, TO(0),
       TO(0), KC_TRNS,
       KC_TRNS,
       KC_NO, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
