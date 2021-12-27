#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * ,-----------------------,
   * |  7  | HOME| END | NUM |
   * |-----+-----+-----+-----|
   * |  7  |  8  |  9  |  0  |
   * |-----+-----+-----+-----|
   * |  4  |  5  |  6  | BACK|
   * |-----+-----+-----+-----|
   * |  1  |  2  |  3  | ENT |
   * `-----------------------'
   */
  LAYOUT_ortho_4x4(
    RGB_TOG, KC_HOME,   KC_END,   KC_NUM,
    KC_P7, KC_P8,   KC_P9,   KC_P0,
    KC_P4, KC_P5,   KC_P6,   KC_BSPC,
    KC_P1, KC_P2, KC_P3, KC_PENT
  )
};

void keyboard_post_init_user(void) {
  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {         // First encoder - top left
    if (clockwise) {
      rgblight_step_noeeprom();
    } else {
      rgblight_step_reverse_noeeprom();

    }
  } else if (index == 1) {  // Second encoder - top right
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }

  return true;
}
