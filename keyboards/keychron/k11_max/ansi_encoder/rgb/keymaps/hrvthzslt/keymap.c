/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

// additional key definitions
#include "keys.h"

#include "macros.c"

enum layers{
    MOD_BASE,
    BASE,
    _NAV,
    _FN2,
    _FUN,
};
    
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [MOD_BASE] = LAYOUT_69_ansi(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        LT_TNAV, KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_DEL,           MA_LCK,
        MT_CTES, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_BSLS,          KC_PSCR,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     MO(_FN2), KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LALT,  KC_LGUI,           KC_SPC,           MT_ALBS,  MO(_FUN),          MT_ALEN,           KC_LGUI,            KC_LEFT, KC_DOWN, KC_RGHT),

    [BASE] = LAYOUT_69_ansi(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_DEL,           MA_LCK,
        KC_LCTL, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_BSLS,          KC_PSCR,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     MO(_FN2), KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LALT,  KC_LGUI,           KC_SPC,           KC_LALT,  MO(_FUN),          KC_ENT,            KC_LGUI,            KC_LEFT, KC_DOWN, KC_RGHT),

    [_NAV] = LAYOUT_69_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU, KC_MCTRL, KC_LNPAD,RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, MA_SUP4,  MA_SUP1, MA_SUP2, MA_SUP3, KC_PGUP,  _______,  _______,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, KC_LEFT,           KC_DOWN, KC_UP,   KC_RGHT,  _______,  _______,  _______,          _______,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, _______,  _______, KC_PGDN, KC_HOME, C_LEFT,   C_RIGHT,  KC_END,   _______, _______,
        _______, _______,  _______,           _______,          KC_DEL,   _______,          _______,           _______,            _______, KC_PGDN, _______),

    [_FN2] = LAYOUT_69_ansi(
        MA_RES,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______,  _______, _______, _______, _______,  _______,	 _______,  _______,          KC_INS,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,           _______, _______, _______, _______,  _______,  _______,  _______,          KC_END,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,           _______,          KC_DEL,   _______,          _______,           _______,            _______, KC_PGDN, _______),

    [_FUN] = LAYOUT_69_ansi(
        KC_TILD, KC_F1,    KC_F2,	 KC_F3,   KC_F4,   KC_F5,	KC_F6,	  KC_F7,   KC_F8,	KC_F9,	 KC_F10,   KC_F11,	 KC_F12,   _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  KC_4,    KC_5,    KC_6,    _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           _______, KC_1,    KC_2,    KC_3,     _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, BAT_LVL,  BAT_LVL, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          KC_DEL,   _______,          _______,           _______,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [MOD_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
        [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
        [_NAV]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
        [_FN2]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
        [_FUN]	   = {ENCODER_CCW_CW(_______, _______)},
    };
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    process_macros(keycode, record);
    return true;
}
