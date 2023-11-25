/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
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
#include "keymap_swiss_fr.h"
#include "sendstring_swiss_fr.h"

enum layers {
	_COLEMAK,
    	_NUMPAD,
	_UNICODE,
    	_MEDIA,
	_COLEMAK_MAC,
    	_NUMPAD_MAC,
	_UNICODE_MAC,
    	_MEDIA_MAC,
};

#define RAISE TT(_UNICODE)
#define LOWER TT(_NUMPAD)
#define MEDIA TT(_MEDIA)
#define LRESET TO(_COLEMAK)
#define SU_LEFT LCTL(KC_LEFT)
#define SU_RGHT LCTL(KC_RGHT)
#define SW_MAC TG(_COLEMAK_MAC)

#define RAISE_M TT(_UNICODE_MAC)
#define LOWER_M TT(_NUMPAD_MAC)
#define MEDIA_M TT(_MEDIA_MAC)
#define LRESET_M TO(_COLEMAK_MAC)
#define SU_L_M LALT(KC_LEFT)
#define SU_R_M LALT(KC_RGHT)
#define SW_UBUN TG(_COLEMAK_MAC)
#define MC_LBRC LALT(KC_5)
#define MC_RBRC LALT(KC_6)
#define MC_LCBR LALT(KC_8)
#define MC_RCBR LALT(KC_9)
#define MC_HOME LGUI(KC_LEFT)
#define MC_END LGUI(KC_RGHT)

#define LOCK LGUI(KC_L)

enum custom_keycodes {
  	DB_ACUT = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/*
	 *
	 ************************************************       UBUNTU       ************************************************
	 *
	 */

	/* COLEMAK
	 * ,--------------------------------------------.                    ,----------------------------------------------.
	 * |   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  BackSP   |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |   Tab   |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   É  |  È        |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |  LShift |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '        |
	 * |---------+------+------+------+------+------|   ^   |    |    À  |------+------+------+------+------+-----------|
	 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   -  |  RShift   |
	 * `--------------------------------------------|       /     \      \----------------------------------------------'
	 *                 | MEDIA | LGUI | LATL | LOWER|Space /       \Enter \  |  RAISE  |Delete| RGUI | RALT |
	 *                 `----------------------------------'         '------------------------------------'
	 */

	 [_COLEMAK] = LAYOUT(
		KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,     KC_8,    KC_9,    KC_0, KC_BSPC,
		KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                        KC_J,    KC_L,     KC_U,    CH_Y, CH_EACU, CH_EGRV,
		KC_LSFT, KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                        KC_H,    KC_N,     KC_E,    KC_I,    KC_O, CH_QUOT,
		KC_LCTL, CH_Z,   KC_X,    KC_C,    KC_V,    KC_B,   CH_CIRC,  CH_AGRV,   KC_K,    KC_M,  KC_COMM,  KC_DOT, CH_MINS, KC_RSFT,
				MEDIA, KC_LGUI, KC_LALT,   LOWER,    KC_SPC,   KC_ENT,  RAISE,  KC_DEL,  KC_RGUI, KC_RALT
	),

	/* NUMPAD
	 * ,--------------------------------------------.                    ,----------------------------------------------.
	 * |   ESC   |      |      |      |      |LRESET|                    | PRSC |      |      |      |      |  Delete   |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |   Tab   |      | Home |  Up  |  End |      |                    | CAPS |   7  |   8  |   9  |   '  |           |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |  LShift |      | Left | Down | Right|      |-------.    ,-------|   /  |   4  |   5  |   6  |   -  |           |
	 * |---------+------+------+------+------+------|   Ç   |    |   `   |------+------+------+------+------+-----------|
	 * |  LCTRL  |   `  | Sup.L|      | Sup.R|      |-------|    |-------|   *  |   1  |   2  |   3  |   +  |           |
	 * `--------------------------------------------|       /     \      \-----------------------------------------------'
	 *                  |MEDIA | LGUI | LATL |LOWER |Space /      \Enter \RAISE |   0  |   .  |      |
	 *                  `----------------------------------'       '------------------------------------'
	 */

	[_NUMPAD] = LAYOUT(
		KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  LRESET,                   KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
		KC_TAB , XXXXXXX, KC_HOME,   KC_UP,  KC_END, XXXXXXX,                   KC_CAPS,    KC_7,    KC_8,    KC_9, CH_QUOT, XXXXXXX,
		KC_LSFT, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                   CH_SLSH,    KC_4,    KC_5,    KC_6, CH_MINS, XXXXXXX,
		KC_LCTL, DB_ACUT, SU_LEFT, XXXXXXX, SU_RGHT, XXXXXXX, CH_CCED,  CH_GRV, CH_ASTR,    KC_1,    KC_2,    KC_3, CH_PLUS, _______,
				  _______, _______, _______, _______, _______, _______, _______,    KC_0,  KC_DOT, XXXXXXX
	),

	/* UNICODE
	 * ,--------------------------------------------.                    ,----------------------------------------------.
	 * |   ESC   |      |      |   <  |   >  |LRESET|                    |      |      |      |      |      |  Delete   |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |   Tab   |      |      |   [  |   ]  |      |                    |      |   %  |   #  |   |  |   '  |           |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |  LShift |      |      |   (  |   )  |      |-------.    ,-------|      |   $  |   @  |   =  |   ~  |           |
	 * |---------+------+------+------+------+------|  LOCK |    |SW_MAC |------+------+------+------+------+-----------|
	 * |  LCTRL  |      |      |   {  |   }  |      |-------|    |-------|      |   &  |   "  |   !  |      |  RShift   |
	 * `--------------------------------------------|       /     \      \----------------------------------------------'
	 *                  | MEDIA| LGUI | LATL |LOWER| Space /      \Enter \RAISE |BackSP| RGUI | RALT |
	 *                  `----------------------------------'      '----------------------------------'
	 */

	[_UNICODE] = LAYOUT(
		KC_ESC , XXXXXXX, XXXXXXX, CH_LABK, CH_RABK, XXXXXXX,                   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,
		KC_TAB , XXXXXXX, XXXXXXX, CH_LBRC, CH_RBRC, XXXXXXX,                   XXXXXXX, CH_PERC, ALGR(KC_3), CH_PIPE, CH_QUOT, XXXXXXX,
		KC_LSFT, XXXXXXX, XXXXXXX, CH_LPRN, CH_RPRN, XXXXXXX,                   XXXXXXX,  CH_DLR, ALGR(KC_2),  CH_EQL, CH_TILD, XXXXXXX,
		KC_LCTL, XXXXXXX, XXXXXXX, CH_LCBR, CH_RCBR, XXXXXXX,    LOCK,  SW_MAC, XXXXXXX, CH_AMPR,    CH_DQUO, CH_EXLM, XXXXXXX, KC_RSFT,
				  _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______
	),

	/* MEDIA
	 * ,-------------------------------------------.                    ,-----------------------------------------.
	 * |   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |BackSP|
	 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | RGB ON | HUE+ | SAT+ | VAL+ |      |      |                    |      | PREV | PLAY | NEXT |      |      |
	 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | MODE   | HUE- | SAT- | VAL- |      |      |-------.    ,-------|      | VOL- | MUTE | VOL+ |      |      |
	 * |--------+------+------+------+------+------|   <   |    |SW_MAC |------+------+------+------+------+------|
	 * |        |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
	 * `-------------------------------------------|       /     \      \-----------------------------------------'
	 *                 | MEDIA| LGUI | LATL |LOWER| Space /      \Enter \RAISE |BackSP| RGUI | RALT |
	 *                 `----------------------------------'      '----------------------------------'
	 */

	[_MEDIA] = LAYOUT(
		KC_ESC ,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,
		RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,  LRESET,                   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
		RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
				  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
	),

	/*
	 *
	 ************************************************         MAC        ************************************************
	 *
	 */

	/* COLEMAK
	 * ,--------------------------------------------.                    ,----------------------------------------------.
	 * |   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  BackSP   |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |   Tab   |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   É  |  È        |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |  LShift |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '        |
	 * |---------+------+------+------+------+------|   ^   |    |    À  |------+------+------+------+------+-----------|
	 * |   CMD   |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   -  |  RShift   |
	 * `--------------------------------------------|       /     \      \----------------------------------------------'
	 *                 | MEDIA | LCTL | LATL | LOWER|Space /       \Enter \  |  RAISE  |Delete| RGUI | RALT |
	 *                 `----------------------------------'         '------------------------------------'
	 */

	 [_COLEMAK_MAC] = LAYOUT(
		KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,     KC_8,    KC_9,    KC_0, KC_BSPC,
		KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                        KC_J,    KC_L,     KC_U,    CH_Y, CH_EACU, CH_EGRV,
		KC_LSFT, KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                        KC_H,    KC_N,     KC_E,    KC_I,    KC_O, CH_QUOT,
		KC_LGUI, CH_Z,   KC_X,    KC_C,    KC_V,    KC_B,   CH_CIRC,  CH_AGRV,   KC_K,    KC_M,  KC_COMM,  KC_DOT, CH_MINS, KC_RSFT,
				MEDIA, KC_LCTL, KC_LALT, LOWER_M,    KC_SPC,   KC_ENT,RAISE_M,  KC_DEL,  KC_RGUI, KC_RALT
	),

	/* NUMPAD
	 * ,--------------------------------------------.                    ,----------------------------------------------.
	 * |   ESC   |      |      |      |      |LRESET|                    | PRSC |      |      |      |      |  Delete   |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |   Tab   |      | Home |  Up  |  End |      |                    | CAPS |   7  |   8  |   9  |   '  |           |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |  LShift |      | Left | Down | Right|      |-------.    ,-------|   /  |   4  |   5  |   6  |   -  |           |
	 * |---------+------+------+------+------+------|   Ç   |    |   `   |------+------+------+------+------+-----------|
	 * |   CMD   |   `  | Sup.L|      | Sup.R|      |-------|    |-------|   *  |   1  |   2  |   3  |   +  |           |
	 * `--------------------------------------------|       /     \      \-----------------------------------------------'
	 *                  |MEDIA | LGUI | LATL |LOWER |Space /      \Enter \RAISE |   0  |   .  |      |
	 *                  `----------------------------------'       '------------------------------------'
	 */

	[_NUMPAD_MAC] = LAYOUT(
		KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  LRESET,                   KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
		KC_TAB , XXXXXXX, MC_HOME,   KC_UP,  MC_END, XXXXXXX,                   KC_CAPS,    KC_7,    KC_8,    KC_9, CH_QUOT, XXXXXXX,
		KC_LSFT, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                   CH_SLSH,    KC_4,    KC_5,    KC_6, CH_MINS, XXXXXXX,
		KC_LGUI, DB_ACUT,  SU_L_M, XXXXXXX,  SU_R_M, XXXXXXX, CH_CCED,  CH_GRV, CH_ASTR,    KC_1,    KC_2,    KC_3, CH_PLUS, _______,
				  _______, _______, _______, _______, _______, _______, _______,    KC_0,  KC_DOT, XXXXXXX
	),

	/* UNICODE
	 * ,--------------------------------------------.                    ,----------------------------------------------.
	 * |   ESC   |      |      |   <  |   >  |LRESET|                    |      |      |      |      |      |  Delete   |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |   Tab   |      |      |   [  |   ]  |      |                    |      |   %  |   #  |   |  |   '  |           |
	 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
	 * |  LShift |      |      |   (  |   )  |      |-------.    ,-------|      |   $  |   @  |   =  |   ~  |           |
	 * |---------+------+------+------+------+------|  LOCK |    |SW_UBUN|------+------+------+------+------+-----------|
	 * |   CMD   |      |      |   {  |   }  |      |-------|    |-------|      |   &  |   "  |   !  |      |  RShift   |
	 * `--------------------------------------------|       /     \      \----------------------------------------------'
	 *                  | MEDIA| LGUI | LATL |LOWER| Space /      \Enter \RAISE |BackSP| RGUI | RALT |
	 *                  `----------------------------------'      '----------------------------------'
	 */

	[_UNICODE_MAC] = LAYOUT(
		KC_ESC , XXXXXXX, XXXXXXX, CH_LABK, CH_RABK, XXXXXXX,                   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,
		KC_TAB , XXXXXXX, XXXXXXX, MC_LBRC, MC_RBRC, XXXXXXX,                   XXXXXXX, CH_PERC, ALGR(KC_3), CH_PIPE, CH_QUOT, XXXXXXX,
		KC_LSFT, XXXXXXX, XXXXXXX, CH_LPRN, CH_RPRN, XXXXXXX,                   XXXXXXX,  CH_DLR, LALT(KC_G),  CH_EQL, CH_TILD, XXXXXXX,
		KC_LGUI, XXXXXXX, XXXXXXX, MC_LCBR, MC_RCBR, XXXXXXX,    LOCK, SW_UBUN, XXXXXXX, CH_AMPR,    CH_DQUO, CH_EXLM, XXXXXXX, KC_RSFT,
				  _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______
	),

	/* MEDIA
	 * ,-------------------------------------------.                    ,-----------------------------------------.
	 * |   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |BackSP|
	 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | RGB ON | HUE+ | SAT+ | VAL+ |      |      |                    |      | PREV | PLAY | NEXT |      |      |
	 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | MODE   | HUE- | SAT- | VAL- |      |      |-------.    ,-------|      | VOL- | MUTE | VOL+ |      |      |
	 * |--------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
	 * |        |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
	 * `-------------------------------------------|       /     \      \-----------------------------------------'
	 *                 | MEDIA| LGUI | LATL |LOWER| Space /      \Enter \RAISE |BackSP| RGUI | RALT |
	 *                 `----------------------------------'      '----------------------------------'
	 */

	[_MEDIA_MAC] = LAYOUT(
		KC_ESC ,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,
		RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,  LRESET,                   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
		RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
				  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
	)
};


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUMPAD, _UNICODE, _MEDIA);
    return state;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
}

void render_space(void) {
	static const char PROGMEM space_line[] = {
        0x07, 0x07, 0x07, 0x07, 0x07, 0};
	oled_write_P(space_line, false);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case DB_ACUT:
      if (record->event.pressed) {
      	SEND_STRING(
      	  SS_DOWN(X_LSFT)
      	  SS_TAP(X_EQL)
      	  SS_UP(X_LSFT)
      	  SS_TAP(X_SPC)
      	);
      }
      return false;
  }
  return true;
}

void render_mod_status_cl_alt(uint8_t modifiers) {
    static const char PROGMEM cl_off_1[] = {0x24, 0x25, 0};
    static const char PROGMEM cl_off_2[] = {0x44, 0x45, 0};
    static const char PROGMEM cl_on_1[] = {0x64, 0x65, 0};
    static const char PROGMEM cl_on_2[] = {0x84, 0x85, 0};

    static const char PROGMEM alt_off_1[] = {0x26, 0x27, 0};
    static const char PROGMEM alt_off_2[] = {0x46, 0x47, 0};
    static const char PROGMEM alt_on_1[] = {0x66, 0x67, 0};
    static const char PROGMEM alt_on_2[] = {0x86, 0x87, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xA0, 0};
    static const char PROGMEM off_off_2[] = {0xC0, 0};
    static const char PROGMEM on_off_1[] = {0xA2, 0};
    static const char PROGMEM on_off_2[] = {0xC2, 0};
    static const char PROGMEM off_on_1[] = {0xA1, 0};
    static const char PROGMEM off_on_2[] = {0xC1, 0};
    static const char PROGMEM on_on_1[] = {0xA3, 0};
    static const char PROGMEM on_on_2[] = {0xC3, 0};

    if(host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        oled_write_P(cl_on_1, false);
    } else {
        oled_write_P(cl_off_1, false);
    }

    if ((host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);  
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        oled_write_P(cl_on_2, false);
    } else {
        oled_write_P(cl_off_2, false);
    }

    if ((host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0xA4, 0xA5, 0};
    static const char PROGMEM ctrl_off_2[] = {0xC4, 0xC5, 0};
    static const char PROGMEM ctrl_on_1[] = {0x60, 0x61, 0};
    static const char PROGMEM ctrl_on_2[] = {0x80, 0x81, 0};

    static const char PROGMEM shift_off_1[] = {0xA6, 0xA7, 0};
    static const char PROGMEM shift_off_2[] = {0xC6, 0xC7, 0};
    static const char PROGMEM shift_on_1[] = {0x62, 0x63, 0};
    static const char PROGMEM shift_on_2[] = {0x82, 0x83, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xA0, 0};
    static const char PROGMEM off_off_2[] = {0xC0, 0};
    static const char PROGMEM on_off_1[] = {0xA2, 0};
    static const char PROGMEM on_off_2[] = {0xC2, 0};
    static const char PROGMEM off_on_1[] = {0xA1, 0};
    static const char PROGMEM off_on_2[] = {0xC1, 0};
    static const char PROGMEM on_on_1[] = {0xA3, 0};
    static const char PROGMEM on_on_2[] = {0xC3, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if((modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_layout_logo(void) {
    static const char PROGMEM kimiko_logo[] = {
        0x01, 0x02, 0x03, 0x04, 0x05, 0};
    static const char PROGMEM ubuntu_logo[] = {
        0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0};
    static const char PROGMEM mac_logo[] = {
        0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0};
	
	switch (get_highest_layer(layer_state)) {
		case _COLEMAK:
		case _NUMPAD:
		case _UNICODE:
			oled_write_P(ubuntu_logo, false);
			break;
		case _COLEMAK_MAC:
		case _NUMPAD_MAC:
		case _UNICODE_MAC:
			oled_write_P(mac_logo, false);
			break;
		default:
			oled_write_P(kimiko_logo, false);
			break;
	}
}

void render_logo(void) {
    static const char PROGMEM kimiko_logo[] = {
        0x01, 0x02, 0x03, 0x04, 0x05, 0};
	oled_write_P(kimiko_logo, false);
}

void render_otter(void) {
	static const char PROGMEM otter_image[] = {
		0x71, 0x72, 0x73, 0x74, 0x75,
		0x91, 0x92, 0x93, 0x94, 0x95,
		0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0};
    oled_write_P(otter_image, false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x07, 0x08, 0x09, 0x10, 0x07,
        0x07, 0x28, 0x29, 0x2A, 0x07,
        0x07, 0x48, 0x49, 0x4A, 0x07, 0};
    static const char PROGMEM unicode_layer[] = {
        0x07, 0x0B, 0x0C, 0x21, 0x07,
        0x07, 0x2B, 0x2C, 0x2D, 0x07,
        0x07, 0x48, 0x49, 0x4A, 0x07, 0};
    static const char PROGMEM numpad_layer[] = {
        0x07, 0x08, 0x09, 0x10, 0x07,
        0x07, 0x2E, 0x2F, 0x30, 0x07,
        0x07, 0x4E, 0x4F, 0x50, 0x07, 0};
    static const char PROGMEM media_layer[] = {
        0x07, 0x08, 0x09, 0x10, 0x07,
        0x07, 0x31, 0x32, 0x33, 0x07,
        0x07, 0x51, 0x52, 0x53, 0x07, 0};
	
	switch (get_highest_layer(layer_state)) {
		case _NUMPAD:
		case _NUMPAD_MAC:
			oled_write_P(numpad_layer, false);
			break;
		case _UNICODE:
		case _UNICODE_MAC:
			oled_write_P(unicode_layer, false);
			break;
		case _MEDIA:
			oled_write_P(media_layer, false);
			break;
		default:
			oled_write_P(default_layer, false);
			break;
	}
}

void render_layer_state_secondary_icon(void) {
	static const char PROGMEM hash_image[] = {
		0x6D, 0x6E, 0x6F, 0x70, 0x07,
		0x8D, 0x8E, 0x8F, 0x90, 0x07,
		0xAD, 0xAE, 0xAF, 0xB0, 0x07, 0
	};
	
	static const char PROGMEM code_image[] = {
		0x68, 0x69, 0x6A, 0x6B, 0x6C,
		0x88, 0x89, 0x8A, 0x8B, 0x8C,
		0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0
	};
	
	static const char PROGMEM fast_forward_image[] = {
		0x19, 0x1A, 0x1B, 0x1C, 0x1D,
		0x39, 0x3A, 0x3B, 0x3C, 0x3D,
		0x59, 0x5A, 0x5B, 0x5C, 0x5d, 0
	};
	
	static const char PROGMEM keyboard_image[] = {
		0x14, 0x15, 0x16, 0x17, 0x18,
		0x34, 0x35, 0x36, 0x37, 0x38,
		0x54, 0x55, 0x56, 0x57, 0x58, 0
	};
	
	switch (get_highest_layer(layer_state)) {
		case _NUMPAD:
		case _NUMPAD_MAC:
			oled_write_P(hash_image, false);
			break;
		case _UNICODE:
		case _UNICODE_MAC:
			oled_write_P(code_image, false);
			break;
		case _MEDIA:
			oled_write_P(fast_forward_image, false);
			break;
		default:
			oled_write_P(keyboard_image, false);
			break;
	}
}

void render_status_main(void) {
	render_space();
	render_layout_logo();
	render_space();
	render_mod_status_cl_alt(get_mods()|get_oneshot_mods());
	render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
	render_space();
	render_layer_state();
	render_space();
	render_layer_state_secondary_icon();
}

void render_status_secondary(void) {
	render_space();
	render_space();
	render_logo();
	render_space();
	render_space();
	render_space();
	render_space();
	render_otter();
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();
    } else {
        render_status_secondary();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    }
    return false;
}

#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_COLEMAK] =   { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  },
    [_NUMPAD] =  { ENCODER_CCW_CW(KC_TAB, RGB_HUI),           ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [_UNICODE] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(RGB_HUI, RGB_HUD) },
    [_MEDIA] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_COLEMAK_MAC] =   { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)  },
    [_NUMPAD_MAC] =  { ENCODER_CCW_CW(KC_TAB, RGB_HUI),           ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [_UNICODE_MAC] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(RGB_HUI, RGB_HUD) },
    [_MEDIA_MAC] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
};
#endif // ENCODER_MAP_ENABLE 


