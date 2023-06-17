// Copyright 2021 Christoph Rehmann (crehmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* USB Device descriptor parameter */
// #define VENDOR_ID    0xFEED 
// #define PRODUCT_ID   0xB077
// #define DEVICE_VER   0x0001
// #define MANUFACTURER crehmann
// #define PRODUCT      TPS42

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS  8
#define MATRIX_COLS  6



/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D2

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X32
#define SPLIT_OLED_ENABLE
#endif

#ifdef PS2_USE_INT
#define PS2_CLOCK_PIN   E6
#define PS2_DATA_PIN    D7

#define PS2_INT_INIT()  do {    \
    EICRB |= ((1<<ISC61) |      \
              (0<<ISC60));      \
    } while (0)
#define PS2_INT_ON()  do {      \
     EIMSK |= (1<<INT6);        \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT6);        \
} while (0)
#define PS2_INT_VECT   INT6_vect
#define PS2_MOUSE_ROTATE 90 /* Compensate for East-facing device orientation. */
#endif
