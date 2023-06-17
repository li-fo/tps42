// Copyright 2021 Christoph Rehmann (crehmann)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "tps42.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,                          R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,                          R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29,                          R30, R31, R32, R33, R34, R35, \
                             L36, L37, L38,      R39, R40, R41 \
) \
{ \
    { L05,   L04,   L03,   L02,   L01,   L00   }, \
    { L17,   L16,   L15,   L14,   L13,   L12   }, \
    { L29,   L28,   L27,   L26,   L25,   L24   }, \
    { L38,   L37,   L36,   KC_NO, KC_NO, KC_NO }, \
    { R06,   R07,   R08,   R09,   R10,   R11   }, \
    { R18,   R19,   R20,   R21,   R22,   R23   }, \
    { R30,   R31,   R32,   R33,   R34,   R35   }, \
    { R39,   R40,   R41,   KC_NO, KC_NO, KC_NO }, \
}

#define LAYOUT_stack(                               \
    L00, L01, L02, L03, L04, L05,                   \
    L12, L13, L14, L15, L16, L17,                   \
    L24, L25, L26, L27, L28, L29,                   \
                   L36, L37, L38,                   \
                                                    \
                  R06, R07, R08, R09, R10, R11,     \
                  R18, R19, R20, R21, R22, R23,     \
                  R30, R31, R32, R33, R34, R35,     \
                  R39, R40, R41                     \
)                                                   \
{                                                   \
    { L05,   L04,   L03,   L02,   L01,   L00   }, \
    { L17,   L16,   L15,   L14,   L13,   L12   }, \
    { L29,   L28,   L27,   L26,   L25,   L24   }, \
    { L38,   L37,   L36,   KC_NO, KC_NO, KC_NO }, \
    { R06,   R07,   R08,   R09,   R10,   R11   }, \
    { R18,   R19,   R20,   R21,   R22,   R23   }, \
    { R30,   R31,   R32,   R33,   R34,   R35   }, \
    { R39,   R40,   R41,   KC_NO, KC_NO, KC_NO }, \
}
