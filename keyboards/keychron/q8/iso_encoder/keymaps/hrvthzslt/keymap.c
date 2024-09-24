/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// macros

enum custom_keycodes {
    MA_SUP1 = SAFE_RANGE,
    MA_SUP2,
    MA_SUP3,
    MA_SUP4,
};

bool press_super(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(keycode);
    } else {
        unregister_code(keycode);
        unregister_code(KC_LGUI);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MA_SUP1:
            press_super(KC_1, record);
            break;
        case MA_SUP2:
            press_super(KC_2, record);
            break;
        case MA_SUP3:
            press_super(KC_3, record);
            break;
        case MA_SUP4:
            press_super(KC_4, record);
            break;
    }
    return true;
}
// clang-format off

enum layers {
    MOD_BASE,
    BASE,
    _NAV,
    _FN2,
    _FUN
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define LT_TNAV LT(_NAV,KC_TAB)
#define MT_CTES MT(MOD_LCTL,KC_ESC)
#define MT_ALBS MT(MOD_LALT,KC_BSPC)
#define MT_ALEN MT(MOD_LALT|MOD_RALT,KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MOD_BASE] = LAYOUT_iso_70(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        LT_TNAV, KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,                    KC_DEL,
        MT_CTES, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,           KC_HOME,
        KC_LSFT, KC_NUBS,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,     KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, MO(_NAV), KC_LWIN,           KC_SPC,           MT_ALBS,  MO(_FUN),          MT_ALEN,           KC_LWIN,            KC_LEFT, KC_DOWN, KC_RGHT),

    [BASE] = LAYOUT_iso_70(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,                    KC_DEL,
        KC_LCTL, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,           KC_HOME,
        KC_LSFT, KC_NUBS,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,     KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, MO(_NAV), KC_LWIN,           KC_SPC,           KC_LALT,  MO(_FUN),          KC_ENT,            KC_LWIN,            KC_LEFT, KC_DOWN, KC_RGHT),

    [_NAV] = LAYOUT_iso_70(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI,  KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, MA_SUP4,  MA_SUP1,  MA_SUP2, MA_SUP3, KC_PGUP,  _______,  _______,                    _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, NK_TOGG, _______, _______,  _______,  KC_PGDN, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,           _______,           _______,            _______, _______, _______),

    [_FN2] = LAYOUT_iso_70(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI,  KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______,  _______, _______, _______,  _______,  _______,                    _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______,  _______,  _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______,  NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,           _______,           _______,            _______, _______, _______),

    [_FUN] = LAYOUT_iso_70(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______,  _______, _______, _______,  _______,  _______,                    _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______,  _______,  _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______,  _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,           _______,           _______,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MOD_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NAV]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN2]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FUN]   = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE
