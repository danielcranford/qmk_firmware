#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  // Moonlander keycodes
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,

  // Custom keycodes
  //KC_LCMB,
  //KC_RCMB,
};

enum layers {
  DEFAULT,
  CMBMAIN,
  OSMMAIN,
  MIRMAIN,
  JMP,
  JMPLEFT,
  JMPRIGHT,
  MIRNAV,
  MIRNUM,
  MIRFN,
  MIRSYM,
  MIRMEDIA,
  MIRMOUSE,
  OSMNAV,
  OSMNUM,
  OSMFN,
  SYMBOLS,
  MEDIA,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,              KC_2,           KC_3,           KC_4,           KC_5,           TG(MIRMAIN),                 WEBUSB_PAIR, KC_6,                    KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_EQUAL,       KC_Q,              KC_W,           KC_E,           KC_R,           KC_T,           TG(CMBMAIN),                 TG(OSMMAIN), KC_Y,                    KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,      
    KC_DELETE,      KC_A,              KC_S,           KC_D,           KC_F,           KC_G,           TG(MEDIA),                   TG(JMP),     KC_H,                    KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,       
    KC_LSHIFT,      KC_Z,              KC_X,           KC_C,           KC_V,           KC_B,                                                     KC_N,                    KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,      
    KC_LCTRL,       KC_LGUI,           KC_LALT,        KC_LEFT,        KC_RIGHT,       MT(MOD_LALT, KC_APPLICATION),                             MT(MOD_LCTL, KC_ESCAPE), KC_UP,          KC_DOWN,        LGUI(KC_TAB),   TT(MEDIA),      TT(SYMBOLS),         
    KC_BSPACE,      LT(MIRNAV,KC_TAB), DEBUG,        KC_LALT,        KC_ENTER,       KC_SPACE
  ),
  [CMBMAIN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT, KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT, KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ESCAPE,      KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_BSPACE,      KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_ENTER,       KC_SPACE
  ),
  [OSMMAIN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(OSMNAV),        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, OSL(OSMNUM),        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_BSPACE,      KC_TAB,         KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_SPACE
  ),
  [MIRMAIN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, KC_Q), MT(MOD_LALT, KC_W), MT(MOD_LCTL, KC_E), MT(MOD_LSFT, KC_R), MT(MOD_LSFT, KC_T),           KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LSFT, KC_Y),           MT(MOD_LSFT, KC_U), MT(MOD_LCTL, KC_I),     MT(MOD_LALT, KC_O), MT(MOD_LGUI, KC_P),      KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F), MT(MOD_LSFT, KC_G),           KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LSFT, KC_H),           MT(MOD_LSFT, KC_J), MT(MOD_LCTL, KC_K),     MT(MOD_LALT, KC_L), MT(MOD_LGUI, KC_SCOLON), KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, KC_Z), MT(MOD_LALT, KC_X), MT(MOD_LCTL, KC_C), MT(MOD_LSFT, KC_V), MT(MOD_LSFT, KC_B),                                           MT(MOD_LSFT, KC_N),           MT(MOD_LSFT, KC_M), MT(MOD_LCTL, KC_COMMA), MT(MOD_LALT, KC_DOT),MT(MOD_LGUI, KC_SLASH), KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LT(MIRMEDIA,KC_ESCAPE),KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, LT(MIRFN,KC_DELETE),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LT(MIRNAV,KC_BSPACE),LT(MIRMOUSE,KC_TAB),  KC_TRANSPARENT,                 KC_TRANSPARENT, LT(MIRSYM,KC_ENTER), LT(MIRNUM,KC_SPACE)
  ),
  [JMP] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ESCAPE,      MO(JMPLEFT),    KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, MO(JMPRIGHT),         KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_BSPACE,      KC_TAB,         KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_SPACE
  ),
  [JMPLEFT] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, MO(MIRFN),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, MO(MIRSYM),          MO(MIRNUM)
  ),
  [JMPRIGHT] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(MIRMEDIA),         KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MO(MIRNAV),          MO(MIRMOUSE),         KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRNAV] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_INSERT,      KC_HOME,        KC_UP,          KC_END,         KC_PGUP,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_CAPSLOCK,    KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDOWN,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(KC_Y),     KC_PC_PASTE,    KC_PC_COPY,     KC_PC_CUT,      KC_PC_UNDO,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_BSPACE
  ),
  [MIRNUM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LBRACKET,    KC_7,           KC_8,           KC_9,           KC_RBRACKET,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_QUOTE,       KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_BSLASH,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,         KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_0,           KC_MINUS,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRFN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PSCREEN,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_SCROLLLOCK,  KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_PAUSE,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_APPLICATION, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_TAB,         KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRSYM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_DQUO,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_PLUS,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_PIPE,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_RPRN,        KC_UNDS,        KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRMEDIA] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE
  ),
  [MIRMOUSE] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_MS_WH_UP,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(KC_Y),     KC_PC_PASTE,    KC_PC_COPY,     KC_PC_CUT,      KC_PC_UNDO,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN3
  ),
  [OSMNAV] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_INSERT,      KC_HOME,        KC_UP,          KC_END,         KC_PGUP,        KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),  KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_CAPSLOCK,    KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDOWN,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(KC_Y),     KC_PC_PASTE,    KC_PC_COPY,     KC_PC_CUT,      KC_PC_UNDO,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, OSL(OSMFN),         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [OSMNUM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LBRACKET,    KC_7,           KC_8,           KC_9,           KC_RBRACKET,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_QUOTE,       KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_LSFT),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LGUI),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_BSLASH,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(OSMFN),         KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_0,           KC_MINUS,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [OSMFN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESCAPE,      KC_F7,          KC_F8,          KC_F9,          KC_PSCREEN,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_APPLICATION, KC_F4,          KC_F5,          KC_F6,          KC_SCROLLLOCK,  KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_LSFT),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LGUI),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_PAUSE,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SYMBOLS] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,         
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_COMMA,       HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,RGB_MOD,                                                                                                        RGB_TOG,        KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT, 
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
  [MEDIA] = LAYOUT_moonlander(
    AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,          
    MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DEBUG, 
    MU_MOD,         KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();

  // Disable combos by default
  combo_disable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [MIRMAIN] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,241,249}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {89,241,249}, {0,0,0}, {0,0,0} },

    [JMP] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [JMPLEFT] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {89,241,249}, {0,0,0}, {0,0,0} },

    [JMPRIGHT] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,241,249}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [MIRNAV] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0}, {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0}, {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0}, {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {131,241,249}, {131,241,249}, {0,0,0}, {0,0,0} },

    [MIRNUM] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {161,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {0,0,0}, {0,0,0}, {0,0,0} },

    [MIRFN] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,0,0}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [MIRSYM] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {89,241,249}, {89,241,249}, {0,0,0}, {0,0,0}, {89,241,249}, {89,241,249}, {89,241,249}, {0,0,0}, {0,0,0}, {89,241,249}, {89,241,249}, {89,241,249}, {0,0,0}, {0,0,0}, {89,241,249}, {89,241,249}, {89,241,249}, {89,241,249}, {0,0,0}, {89,241,249}, {89,241,249}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {0,0,0}, {0,0,0} },

    [MIRMEDIA] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {210,241,249}, {0,0,0}, {0,0,0} },

    [MIRMOUSE] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {42,241,249}, {42,241,249}, {0,0,0}, {0,0,0}, {42,241,249}, {42,241,249}, {42,241,249}, {0,0,0}, {0,0,0}, {42,241,249}, {42,241,249}, {42,241,249}, {0,0,0}, {0,0,0}, {42,241,249}, {42,241,249}, {42,241,249}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {42,241,249}, {0,0,0}, {0,0,0} },

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
    case MIRMAIN:
      set_layer_color(MIRMAIN);
      break;
    case JMP:
      set_layer_color(JMP);
      break;
    case JMPLEFT:
      set_layer_color(JMPLEFT);
      break;
    case JMPRIGHT:
      set_layer_color(JMPRIGHT);
      break;
    case MIRNAV:
      set_layer_color(MIRNAV);
      break;
    case MIRNUM:
      set_layer_color(MIRNUM);
      break;
    case MIRFN:
      set_layer_color(MIRFN);
      break;
    case MIRSYM:
      set_layer_color(MIRSYM);
      break;
    case MIRMEDIA:
      set_layer_color(MIRMEDIA);
      break;
    case MIRMOUSE:
      set_layer_color(MIRMOUSE);
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
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
  }
  return true;
}

enum combos_enum {
  ESC_F,
  ESC_D,
  ESC_S,
  ESC_A,

  ESC_V,
  BSPACE_V,
  TAB_V,

  DEL_J,
  DEL_K,
  DEL_L,
  DEL_SCOLON,

  DEL_M,
  SPC_M,
  ENTR_M,


  COMBO_LENGTH
};

const uint16_t PROGMEM combos_arr[COMBO_LENGTH][3] = {
  [ESC_F]   = {KC_F, KC_ESCAPE, COMBO_END},
  [ESC_D]    = {KC_D, KC_ESCAPE, COMBO_END},
  [ESC_S]     = {KC_S, KC_ESCAPE, COMBO_END},
  [ESC_A]     = {KC_A, KC_ESCAPE, COMBO_END},

  // Combos for thumb keys. 
  [ESC_V] = {KC_V, KC_ESCAPE, COMBO_END},
  [BSPACE_V]  = {KC_V, KC_BSPACE, COMBO_END},
  [TAB_V] = {KC_V, KC_TAB, COMBO_END},

  // Home row only combos for mods
  [DEL_J]   = {KC_DELETE, KC_J, COMBO_END},
  [DEL_K]    = {KC_DELETE, KC_K, COMBO_END},
  [DEL_L]     = {KC_DELETE, KC_L, COMBO_END},
  [DEL_SCOLON]  = {KC_DELETE, KC_SCOLON, COMBO_END},

  // Combos for thumb keys. 
  [DEL_M]    = {KC_M, KC_DELETE, COMBO_END},
  [SPC_M]   = {KC_M, KC_SPACE, COMBO_END},
  [ENTR_M] = {KC_M, KC_ENTER, COMBO_END},




};


combo_t key_combos[COMBO_LENGTH] = {
  [ESC_F]   = COMBO(combos_arr[ESC_F], KC_LSHIFT),
  [ESC_D]    = COMBO(combos_arr[ESC_D], KC_LCTRL),
  [ESC_S]     = COMBO(combos_arr[ESC_S], KC_LALT),
  [ESC_A]     = COMBO(combos_arr[ESC_A], KC_LGUI),

  [ESC_V] = COMBO_ACTION(combos_arr[ESC_V]),
  [BSPACE_V]  = COMBO_ACTION(combos_arr[BSPACE_V]),
  [TAB_V] = COMBO_ACTION(combos_arr[TAB_V]),

  [DEL_J]   = COMBO(combos_arr[DEL_J], KC_LSHIFT),
  [DEL_K]    = COMBO(combos_arr[DEL_K], KC_LCTRL),
  [DEL_L]     = COMBO(combos_arr[DEL_L], KC_LALT),
  [DEL_SCOLON]  = COMBO(combos_arr[DEL_SCOLON], KC_LGUI),

  [DEL_M]    = COMBO_ACTION(combos_arr[DEL_M]),
  [SPC_M]   = COMBO_ACTION(combos_arr[SPC_M]),
  [ENTR_M] = COMBO_ACTION(combos_arr[ENTR_M]),



};

uint16_t COMBO_LEN = COMBO_LENGTH;

static void layer_pressed(uint8_t layer, bool pressed) {
  if(pressed) {
    layer_on(layer);
  } else {
    layer_off(layer);
  }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index)
  {
  case ESC_V:
    layer_pressed(MIRMEDIA, pressed);
    break;
  case BSPACE_V:
    layer_pressed(MIRNAV, pressed);
    break;
  case TAB_V:
    layer_pressed(MIRMOUSE, pressed);
    break;

  case DEL_M:
    layer_pressed(MIRFN, pressed);
    break;
  case SPC_M:
    layer_pressed(MIRNUM, pressed);
    break;
  case ENTR_M:
    layer_pressed(MIRSYM, pressed);
    break;
    
  }
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  // Enable combos only when combo layer is one of the active layers
  if(layer_state_cmp(state, CMBMAIN)) {
    combo_enable();
  } else {
    combo_disable();
  }
  return state;
}

void oneshot_mods_changed_user(uint8_t mods) {
}
void oneshot_layer_changed_user(uint8_t layer) {
}
