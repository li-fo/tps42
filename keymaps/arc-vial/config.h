
/* VIAL UID for TPS42, change PGH 230613*/
#define VIAL_KEYBOARD_UID \
    { 0x55, 0xC2, 0x6B, 0xED, 0xAF, 0xB7, 0x9D, 0x9B }

#define VIAL_UNLOCK_COMBO_ROWS \
    { 0, 4 }
#define VIAL_UNLOCK_COMBO_COLS \
    { 0, 5 }

/* default layer count */
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Copyright 2021 Christoph Rehmann (crehmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
// #define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.

#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Using the right side as master
#define MASTER_RIGHT

#ifdef PS2_MOUSE_ENABLE
#define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_RIGHT)// using the right mouse button for scrolling (other buttons can be configured)
#define PS2_MOUSE_SCROLL_BTN_SEND 500

#define PS2_MOUSE_X_MULTIPLIER 2
#define PS2_MOUSE_Y_MULTIPLIER 2
#define PS2_MOUSE_V_MULTIPLIER 3

#define PS2_MOUSE_SCROLL_DIVISOR_H 4
#define PS2_MOUSE_SCROLL_DIVISOR_V 4
#endif


// caps word 관련 항목
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define NO_ACTION_ONESHOT

// USB 연결된것 마스터 설정
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000

// 왼쪽 / 오른쪽 따로 컴파일 하기 위한 것
#define EE_HANDS

