// Copyright 2021 Christoph Rehmann (crehmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Using the right side as master
#define MASTER_RIGHT

#ifdef PS2_MOUSE_ENABLE
#define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_RIGHT)
#define PS2_MOUSE_SCROLL_BTN_SEND 500

#define PS2_MOUSE_X_MULTIPLIER 2
#define PS2_MOUSE_Y_MULTIPLIER 2
#define PS2_MOUSE_V_MULTIPLIER 3

#define PS2_MOUSE_SCROLL_DIVISOR_H 4 
#define PS2_MOUSE_SCROLL_DIVISOR_V 4 
#endif