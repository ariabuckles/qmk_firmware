#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap.h"

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(KC_TAB,KC_Q,KC_W,KC_F,KC_P,KC_B,KC_J,KC_L,KC_U,KC_Y,KC_SCOLON,KC_BSPACE,MO(4),KC_A,KC_R,KC_S,KC_T,KC_G,KC_M,KC_N,KC_E,KC_I,KC_O,KC_ENTER,RGB_VAD,KC_LSHIFT,KC_X,KC_C,KC_D,KC_V,KC_K,KC_H,KC_COMMA,KC_DOT,KC_SLASH,RGB_VAI,KC_LCTRL,KC_LALT,KC_TRANSPARENT,KC_Z,LOWER,KC_SPACE,KC_NO,RAISE,KC_LGUI,KC_TRANSPARENT,KC_TRANSPARENT,MO(6)),

  [_LOWER] = LAYOUT_planck_grid(KC_TILD,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_MINUS,KC_PLUS,KC_EQUAL,KC_GRAVE,KC_UNDS,KC_LBRACKET,KC_LCBR,KC_LPRN,KC_BSLASH,KC_PIPE,KC_RPRN,KC_RCBR,KC_RBRACKET,KC_QUOTE,KC_DQUO,LED_LEVEL,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,LED_LEVEL,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_SPACE,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_RAISE] = LAYOUT_planck_grid(LGUI(KC_GRAVE),LGUI(KC_Q),LGUI(KC_W),LGUI(KC_E),LGUI(KC_R),LGUI(KC_T),LGUI(KC_Y),LGUI(KC_LEFT),LGUI(KC_UP),LGUI(KC_RIGHT),LGUI(KC_P),KC_ESCAPE,LGUI(KC_TAB),LGUI(KC_A),LGUI(KC_S),LGUI(KC_D),LGUI(KC_F),LGUI(KC_G),LGUI(KC_H),LCTL(KC_PGUP),LGUI(KC_DOWN),LCTL(KC_PGDOWN),LGUI(KC_SCOLON),LGUI(KC_ENTER),LED_LEVEL,KC_LSHIFT,LGUI(KC_X),LGUI(KC_C),LGUI(KC_V),LGUI(KC_V),LGUI(KC_N),LGUI(KC_H),LGUI(KC_COMMA),LGUI(KC_DOT),LGUI(KC_SLASH),LED_LEVEL,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_Z),KC_TRANSPARENT,LGUI(KC_SPACE),KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_ADJUST] = LAYOUT_planck_grid(KC_NO,KC_NO,KC_NO,KC_AUDIO_VOL_UP,KC_MEDIA_STOP,KC_NO,KC_NO,KC_MS_BTN3,KC_MS_UP,KC_MS_WH_LEFT,KC_MS_WH_RIGHT,KC_MS_WH_UP,MO(5),KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_MEDIA_PLAY_PAUSE,KC_NO,KC_MS_BTN1,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_BTN2,KC_MS_WH_DOWN,KC_F11,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F12,KC_NO,KC_NO,KC_NO,KC_NO,KC_TRANSPARENT,KC_NO,KC_NO,KC_TRANSPARENT,KC_NO,KC_NO,KC_NO,KC_NO),

  [_LAYER4] = LAYOUT_planck_grid(KC_ESCAPE,LCTL(KC_Q),LCTL(KC_W),LCTL(KC_F),LCTL(KC_R),LCTL(KC_B),LCTL(KC_Y),LCTL(KC_U),KC_UP,LCTL(KC_E),LCTL(KC_P),KC_ESCAPE,KC_TRANSPARENT,LCTL(KC_A),LCTL(KC_R),KC_ESCAPE,LCTL(KC_T),LCTL(KC_G),KC_BSPACE,KC_LEFT,KC_DOWN,KC_RIGHT,LCTL(KC_O),LCTL(KC_ENTER),KC_TRANSPARENT,LCTL(KC_LSHIFT),LCTL(KC_X),LCTL(KC_C),LCTL(KC_D),LCTL(KC_V),LCTL(KC_N),KC_BSPACE,LCTL(KC_COMMA),LCTL(KC_DOT),KC_GRAVE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(KC_Z),KC_TRANSPARENT,KC_DOT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER5] = LAYOUT_planck_grid(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN3,KC_MS_WH_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_RIGHT,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER6] = LAYOUT_planck_grid(KC_TRANSPARENT,RGB_TOG,KC_TRANSPARENT,RGB_VAD,RGB_VAI,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RESET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,AU_TOG,LED_LEVEL,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,WEBUSB_PAIR,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,MU_TOG,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153}, {43,84,153} },

    [1] = { {0,205,155}, {255,220,201}, {255,220,201}, {255,220,201}, {255,220,201}, {255,220,201}, {255,220,201}, {255,220,201}, {255,220,201}, {255,220,201}, {255,220,201}, {0,205,155}, {0,205,155}, {233,218,217}, {233,218,217}, {233,218,217}, {233,218,217}, {233,218,217}, {233,218,217}, {233,218,217}, {233,218,217}, {233,218,217}, {233,218,217}, {0,205,155}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,183,238}, {0,205,155}, {252,119,255}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155} },

    [2] = { {0,205,155}, {0,205,155}, {0,205,155}, {250,159,255}, {250,159,255}, {0,205,155}, {0,205,155}, {0,205,155}, {0,183,238}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,183,238}, {0,183,238}, {252,119,255}, {0,183,238}, {0,205,155}, {0,205,155}, {0,183,238}, {0,183,238}, {0,183,238}, {0,205,155}, {0,205,155}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {252,119,255}, {0,205,155}, {0,183,238}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155} },

    [3] = { {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {252,119,255}, {0,205,155}, {252,119,255}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155} },

    [4] = { {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {250,159,255}, {0,205,155}, {0,205,155}, {250,159,255}, {250,159,255}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {250,159,255}, {250,159,255}, {250,159,255}, {0,205,155}, {0,205,155}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155} },

    [6] = { {0,183,238}, {0,0,0}, {0,0,0}, {254,198,190}, {250,159,255}, {0,0,0}, {0,183,238}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {249,228,255}, {0,183,238}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,255}, {0,0,0}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {146,224,255}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {0,0,0}, {0,183,238}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {252,119,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
