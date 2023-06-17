/* Copyright 2021 Christoph Rehmann (crehmann)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef PS2_MOUSE_ENABLE
    #include "ps2_mouse.h"
    #include "ps2.h"
#endif

enum layers {
    _BASE = 0,
    _NAVR,
    _SYMB,
    _NUMR,
    _FUNL,
    _ADJL
};

// Aliases for readability
#define BASE     DF(_BASE)
#define NAVR     MO(_NAVR)
#define SYMB     MO(_SYMB)
#define NUMR     MO(_NUMR)
#define FUNL     MO(_FUNL)
#define ADJL     MO(_ADJL)

// Left-hand home row mods
#define GUI_Y   LGUI_T(CH_Y)
#define ALT_X   LALT_T(KC_X)
#define CTL_C   LCTL_T(KC_C)
#define SFT_V   LSFT_T(KC_V)
#define RALT_B  RALT_T(KC_B)

// Right-hand home row mods
#define RALT_N   RALT_T(KC_N)
#define SFT_M    RSFT_T(KC_M)
#define CTL_COM  RCTL_T(KC_COMM)
#define ALT_DOT  LALT_T(KC_DOT)
#define GUI_SLSH RGUI_T(KC_SLSH)

// Left-hand outer column
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)

// Thumbcluster
#define UC_TL1 LT(FUNL, KC_ENT)
#define UC_TL2 LT(NAVR, KC_ENT)
#define UC_TL3 LT(NUMR, KC_ESC)

#define UC_TR3 LT(FUNL, KC_BTN1)
#define UC_TR2 LT(SYMB, KC_SPC)
#define UC_TR1 KC_DEL



// Thumbcluster crehmann 
// #define UC_TL1 CTL_ESC
// #define UC_TL2 LT(NAVR, KC_SPC)
// #define UC_TL3 LT(NUMR, KC_TAB)

// #define UC_TR3 LT(FUNL, KC_BSPC)
// #define UC_TR2 LT(SYMB, KC_ENT)
// #define UC_TR1 KC_DEL


// Shortcuts
#define UC_COPY LCTL(KC_C)
#define UC_PSTE LCTL(KC_V)
#define UC_CUT  LCTL(KC_X)
#define UC_MUTE SGUI(KC_M)
#define UC_OSFT OSM(MOD_LSFT)
#define UC_LTMS LT(MOUS, KC_S)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// /*
//  * Base Layer
//  *
//  *          ,-----------------------------------------.                                               ,-----------------------------------------.
//  *          | TAB  |   Q  |   W  |   E  |   R  |   T  |                                               |   Y  |   U  |   I  |   O  |   P  | Bspc |      
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          | LCtrl|   A  |   S  |   D  |   F  |   G  |                                               |   H  |   J  |   K  |   L  |  ; : |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |LShift|   Z  |   X  |   C  |   F  |   B  |                                               |   N  |   M  |  , < |  . > |  / ? |RShift|
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Enter| ESC  |                   |  BTN1| Space| BTN2 |
//  *                                             | FUNL | NAVR | NUMR |                   |      | SYML |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_BASE] = LAYOUT(
      KC_TAB, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
      KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G   ,                                        KC_H   , KC_J  , KC_K  , KC_L  , KC_SCLN, ,
      KC_LSFT, KC_Z   , KC_X , KC_C   , KC_V   , KC_B   ,                                        KC_N   , KC_M   , KC_COMMA, KC_DOT, KC_SLSH, KC_RSFT  ,
                                                   UC_TL1, UC_TL2 , UC_TL3 ,    KC_BTN1, UC_TR2, KC_BTN2
    ),

// /*
//  * Navigation Layer (Right)
//  *
//  *          ,-----------------------------------------.                                               ,-----------------------------------------.
//  *          |      |      | Mute | VolDn| VolDn|      |                                               | Home | End  |  ↑   |Print |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |Screen|      |      |
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      | Tab  | Save |SelAll| Copy | Paste|                                               |Insert|   ←  |   ↓  |  →   |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      | LWin |      | Close|  Cut | Undo |                                               | Del  | PGUP | PGDN |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   |Bksp  | Space| LAlt  |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_NAVR] = LAYOUT(
      _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,                                        KC_HOME , KC_END , KC_UP, KC_PGDN, _______, _______,
      _______, KC_TAB, LCTL(KC_S), LCTL(KC_A), LCTL(KC_C), LCTL(KC_V),                                        KC_INSERT, KC_LEFT, KC_DOWN  , KC_RGHT,_______ , _______,
      _______, KC_LGUI, _______, LCTL(KC_W), LCTL(KC_X), LCTL(KC_Z),                                        KC_DELETE, KC_PGUP, KC_PGDN, _______, _______ , _______,
                                                   _______, _______, _______,    KC_BSPC, KC_SPACE , KC_LALT
    ),
// --------------------------------------------------------------------------------------------------------------------------------------------------------


// /*
//  * Symbol Layer (Right)
//  
//  *          ,-----------------------------------------.                                               ,-----------------------------------------.
//  *          |      |   `  |   ~  |   |  |   \  |      |                                               |      |   /  |   +  |   =  |   ?  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |   !  |   @  |   #  |   $  |   %  |                                               |   ^  |   &  |   *  |   (  |   )  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |   :  |   ;  |   -  |   [  |   {  |                                               |   }  |   ]  |   _  |   ,  |   .  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space| TAB  |                   | Bksp | Enter|      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  *
    [_SYMB] = LAYOUT(
      _______, KC_GRV , KC_TILD, KC_PIPE, KC_BSLS, _______,                                        _______, KC_SLSH, KC_PLUS, KC_EQL , KC_QUES, _______,
      _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      _______, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR,                                        KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM, KC_DOT , _______,
                                                   _______, KC_SPC , KC_TAB  ,   KC_BSPC, KC_ENT , _______ 
    ),

// /*
//  * Number Layer (Right)
//  *
//  *          ,-----------------------------------------.                                               ,-----------------------------------------.
//  *          |  ~   | \    |  (   |  )   |      |      |                                               |   +  |   7  |   8  |   9  |  0   |      |
//  *          |  `   |      |      |      |      |      |                                               |   =  |      |      |      |      |      |
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      |   %  |   ^  |   &  |   *  |                                               |   +  |   4  |   5  |  6   |  /   |   *  |
//  *          |  ~   |  |   |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |   !  |   @  |   #  |   $  |                                               |   -  |   1  |   2  |  3   |  .   |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   | Bksp | Enter|      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_NUMR] = LAYOUT(
      KC_GRAVE, KC_BSLS, KC_LPRN, KC_RPRN, _______, _______,                                        KC_EQUAL, KC_7   , KC_8   , KC_9   , KC_0, _______,
      LSFT(KC_GRAVE), LSFT(KC_BSLS), KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,                                        KC_KP_PLUS, KC_4   , KC_5   , KC_6   , KC_SLASH, KC_KP_ASTERISK,
      _______, _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR ,                                        KC_KP_MINUS   , KC_1   , KC_2   , KC_3   , KC_DOT , _______,
                                                   _______, _______, _______,    KC_BSPC, KC_ENT , _______ 
    ),

// /*
//  * Function Layer (Left)
//  *
//  *          ,-----------------------------------------.                                               ,-----------------------------------------.
//  *          |      |  F12 |  F7  |  F8  |  F9  | Pause|                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          | LCtrl|  F11 |  F4  |  F5  |  F6  | PrScr|                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |LShift|  F10 |  F1  |  F2  |  F3  | CapsL|                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space|  TAB |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_FUNL] = LAYOUT(
      _______, KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PAUS,                                        _______, _______, _______, _______, _______, _______,
      KC_LCTL, KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_PSCR,                                        _______, _______, _______, _______, _______, _______,
      KC_LSFT, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_CAPS,                                        _______, _______, _______, _______, _______, _______,
                                                   _______, KC_SPC , KC_TAB  ,    _______, _______, _______
    ),

// /*
//  * Adjustment Layer (Left)
//  *
//  *          ,-----------------------------------------.                                               ,-----------------------------------------.
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |M Prev| VolDn| VolDn|M Next|      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      | Mute | Play |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space| TAB  |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_ADJL] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______, 
      _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,                                        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, KC_MUTE, KC_MPLY, _______,                                        _______, _______, _______, _______, _______, _______,
                                                   _______, KC_SPC , KC_TAB  ,    _______, _______, _______
    ),

// -------------------------------------------------------- TEMPLATE -------------------------------------------------------------------------------------
// /*
//  * Layer
//  *
//  *          ,-----------------------------------------.                                               ,-----------------------------------------.
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//                                                    _______, _______, _______,    _______, _______, _______
//     ),
// --------------------------------------------------------------------------------------------------------------------------------------------------------
};

// uncommint this and modify the timings if the home row mods are not working for you
/*
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
            return TAPPING_TERM + 150;
        case ALT_S:
            return TAPPING_TERM + 50;
        case ALT_L:
            return TAPPING_TERM + 50;
        case GUI_SCL:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}
*/


#ifdef PS2_MOUSE_ENABLE
void ps2_mouse_init_user() {
    uint8_t rcv;

    // see p24 https://blogs.epfl.ch/icenet/documents/Ykt3Eext.pdf
    //hex to decimal

    // set TrackPoint sensitivity
    PS2_MOUSE_SEND(0xE2, "tpsens: 0xE2");
    PS2_MOUSE_SEND(0x81, "tpsens: 0x81");
    PS2_MOUSE_SEND(0x4A, "tpsens: 0x4A");
    // PS2_MOUSE_SEND(0x49, "tpsens: 0x80");//128
    PS2_MOUSE_SEND(0x88, "tpsens: 0x94");//136

    // set TrackPoint Negative Inertia factor
    PS2_MOUSE_SEND(0xE2, "tpnegin: 0xE2");
    PS2_MOUSE_SEND(0x81, "tpnegin: 0x81");
    PS2_MOUSE_SEND(0x4D, "tpnegin: 0x4D");
    PS2_MOUSE_SEND(0x06, "tpnegin: 0x06");//6

    // set TrackPoint speed
    // (transfer function upper plateau speed)
    PS2_MOUSE_SEND(0xE2, "tpsp: 0xE2");
    PS2_MOUSE_SEND(0x81, "tpsp: 0x81");
    PS2_MOUSE_SEND(0x60, "tpsp: 0x60");
    PS2_MOUSE_SEND(0x61, "tpsp: 0x61");//97 basic
    // PS2_MOUSE_SEND(0xE6, "tpsp: 0xE6");//200

    // inquire pts status
    rcv = ps2_host_send(0xE2);
    rcv = ps2_host_send(0x2C);
    rcv = ps2_host_recv_response();
    if ((rcv & 1) == 1) {
    // if on, disable pts
    rcv = ps2_host_send(0xE2); 
    rcv = ps2_host_send(0x47); 
    rcv = ps2_host_send(0x2C); 
    rcv = ps2_host_send(0x01); 
    }
    
}
#endif

