/* Copyright 2015-2023 Jack Humbert
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

const key_override_t ctl_space_override = ko_make_basic(MOD_LCTL, KC_SPC, KC_UNDS);

const key_override_t *key_overrides[] = {
	&ctl_space_override
};

enum {
  _BL,
  _SL,
  _NL,
  _AL,
};


#define BL TO(_BL)
#define SL TO(_SL)
#define NL TO(_NL)
#define AL TO(_AL)

#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

 [_BL] = LAYOUT_planck_grid(
     KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   ,  KC_T  , KC_Y   , KC_U  , KC_I   , KC_O   , KC_P   , KC_BSPC,
     KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   ,  KC_G  , KC_H   , KC_J  , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
     AL     , KC_Z   , KC_X   , KC_C   , KC_V   ,  KC_B  , KC_N   , KC_M  , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, OSM_ALT, KC_SPC , OSM_SFT, OSM_CTL, SL    , NL     , XXXXXXX, XXXXXXX, XXXXXXX  
 ),

 [_SL] = LAYOUT_planck_grid(
     KC_ESC ,  KC_TILD, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EXLM, XXXXXXX, KC_BSPC,
     KC_TAB ,  KC_GRV , KC_EQL , KC_LT  , KC_GT  , KC_QUOT, KC_BSLS, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX, KC_ENT ,
     AL     ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DQUO, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, XXXXXXX, XXXXXXX,
     XXXXXXX,  XXXXXXX, XXXXXXX, OSM_ALT, BL     , OSM_SFT, OSM_CTL, XXXXXXX, NL     , XXXXXXX, XXXXXXX, XXXXXXX
 ),

 [_NL] = LAYOUT_planck_grid(
     KC_ESC ,  XXXXXXX, XXXXXXX, KC_UP  , XXXXXXX, XXXXXXX, KC_MINS, KC_7   , KC_8   , KC_9   , XXXXXXX, KC_BSPC,
     KC_TAB ,  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_EQL , KC_4   , KC_5   , KC_6   , XXXXXXX, KC_ENT ,
     AL     ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0   , KC_1   , KC_2   , KC_3   , XXXXXXX, XXXXXXX,
     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, BL     , XXXXXXX, XXXXXXX, SL     , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
 ),



/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_AL] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_SPDU, UG_SPDD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, BL    , _______, _______, _______, _______, _______, _______, _______
)

};

