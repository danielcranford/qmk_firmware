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

#include "oneshot.h"

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


  OS_LSFT,
  OS_LCTL,
  OS_LALT,
  OS_LGUI,

  OSL_JMPL,
  OSL_JMPR,

  OSL_MEDIA,
  OSL_NAV,
  OSL_MOUSE,
  OSL_SYM,
  OSL_NUM,
  OSL_FUN,
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
    KC_BSPACE,      LT(MIRNAV,KC_TAB), KC_LGUI,        KC_LALT,        KC_ENTER,       KC_SPACE
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT, KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT, KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(OSMNAV),     KC_TRANSPARENT,                                 KC_TRANSPARENT, MO(OSMNUM),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT, KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT, KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ESCAPE,      OSL_JMPL,       KC_TRANSPARENT,                                 KC_TRANSPARENT, OSL_JMPR,       KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_BSPACE,      KC_TAB,         KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_SPACE
  ),
  [JMPLEFT] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, OS_LGUI,        OS_LALT,        OS_LCTL,        OS_LSFT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, OSL_FUN,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, OSL_SYM,        OSL_NUM
  ),
  [JMPRIGHT] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OS_LSFT,        OS_LCTL,        OS_LALT,        OS_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL_MEDIA,      KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    OSL_NAV,        OSL_MOUSE,      KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRNAV] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_INSERT,      KC_HOME,        KC_UP,          KC_END,         KC_PGUP,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPSLOCK,    KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDOWN,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(KC_Y),     KC_PC_PASTE,    KC_PC_COPY,     KC_PC_CUT,      KC_PC_UNDO,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_BSPACE
  ),
  [MIRNUM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LBRACKET,    KC_7,           KC_8,           KC_9,           KC_RBRACKET,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_QUOTE,       KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_BSLASH,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_0,           KC_MINUS,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRFN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PSCREEN,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_SCROLLLOCK,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_PAUSE,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_APPLICATION, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_TAB,         KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRSYM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_DQUO,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_PIPE,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_RPRN,        KC_UNDS,        KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRMEDIA] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE
  ),
  [MIRMOUSE] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_MS_WH_UP,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(KC_Y),     KC_PC_PASTE,    KC_PC_COPY,     KC_PC_CUT,      KC_PC_UNDO,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN3
  ),
  [OSMNAV] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_INSERT,      KC_HOME,        KC_UP,          KC_END,         KC_PGUP,        KC_TRANSPARENT, 
    KC_TRANSPARENT, OS_LGUI,        OS_LALT,        OS_LCTL,        OS_LSFT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPSLOCK,    KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDOWN,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(KC_Y),     KC_PC_PASTE,    KC_PC_COPY,     KC_PC_CUT,      KC_PC_UNDO,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, MO(OSMFN),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [OSMNUM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LBRACKET,    KC_7,           KC_8,           KC_9,           KC_RBRACKET,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_QUOTE,       KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OS_LSFT,        OS_LCTL,        OS_LALT,        OS_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_BSLASH,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(OSMFN),      KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_0,           KC_MINUS,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [OSMFN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESCAPE,      KC_F7,          KC_F8,          KC_F9,          KC_PSCREEN,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_APPLICATION, KC_F4,          KC_F5,          KC_F6,          KC_SCROLLLOCK,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OS_LSFT,        OS_LCTL,        OS_LALT,        OS_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_PAUSE,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SYMBOLS] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT, KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,         
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_COMMA,       HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,RGB_MOD,                                                                                                        RGB_TOG,        KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT, 
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,             RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
  [MEDIA] = LAYOUT_moonlander(
    AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, RESET,          
    MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, DEBUG, 
    MU_MOD,         KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,  KC_AUDIO_MUTE,      KC_TRANSPARENT, KC_TRANSPARENT, 
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

/* RGB LED map appears to number keys thusly
0 5 10 15 20 25 29         65 61 56 51 46 41 36
1 6 11 16 21 26 30         66 62 57 52 47 42 37
2 7 12 17 22 27 31         67 63 58 53 48 43 38
3 8 13 18 23 28               64 59 54 49 44 39
4 9 14 19 24    35         71    60 55 50 45 40
             32 33 34   70 69 68
 */

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [MIRMAIN] = { 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, [24] = {210,241,249}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      [32] = {131,241,249}, [33] = {42,241,249}, {0,0,0}, 
      {0,0,0}, 
      
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, [60] = {0,241,249}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      [68] = {161,241,249}, [69] = {89,241,249}, {0,0,0}, 
      {0,0,0} },

    [JMP] = { 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, 
      
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0} },

    [JMPLEFT] = { 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, 
      
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {161,241,249}, {89,241,249}, {0,0,0}, 
      {0,0,0} },

    [JMPRIGHT] = { 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {131,241,249}, {42,241,249}, {0,0,0}, 
      {0,0,0}, 
      
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0} },

    [MIRNAV] = { 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {131,241,249}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {131,241,249}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {131,241,249}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {131,241,249}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {131,241,249}, {0,0,0}, {0,0,0}, 
      {0,0,0}, 
      
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0}, 
      {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0}, 
      {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0}, 
      {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {131,241,249}, 
      {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {131,241,249}, {131,241,249}, {0,0,0}, 
      {0,0,0} },

    [MIRNUM] = { 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, 
      {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, 
      {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, 
      {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {161,241,249}, 
      {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {161,241,249}, {161,241,249}, {0,0,0}, 
      {0,0,0}, 
      
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {161,241,249}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {161,241,249}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {161,241,249}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {161,241,249}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {161,241,249}, {0,0,0}, {0,0,0}, 
      {0,0,0} },

    [MIRFN] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,0,0}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [MIRSYM] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {89,241,249}, {89,241,249}, {0,0,0}, {0,0,0}, {89,241,249}, {89,241,249}, {89,241,249}, {0,0,0}, {0,0,0}, {89,241,249}, {89,241,249}, {89,241,249}, {0,0,0}, {0,0,0}, {89,241,249}, {89,241,249}, {89,241,249}, {89,241,249}, {0,0,0}, {89,241,249}, {89,241,249}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {89,241,249}, {0,0,0}, {0,0,0} },

    [MIRMEDIA] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {0,0,0}, {210,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {210,241,249}, {210,241,249}, {0,0,0}, {0,0,0} },

    [MIRMOUSE] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {42,241,249}, {42,241,249}, {0,0,0}, {0,0,0}, {42,241,249}, {42,241,249}, {42,241,249}, {0,0,0}, {0,0,0}, {42,241,249}, {42,241,249}, {42,241,249}, {0,0,0}, {0,0,0}, {42,241,249}, {42,241,249}, {42,241,249}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {42,241,249}, {42,241,249}, {0,0,0}, {0,0,0} },

    [OSMNAV] = { 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, 
      
      {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0}, 
      {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0},
      {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,0}, 
      {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, {0,0,255}, 
      {0,0,0}, {131,241,249}, {131,241,249}, {131,241,249}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,0}, {0,0,0}, {0,0,0}, 
      {0,0,255} },

    [OSMNUM] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,255}, {0,0,0}, {161,241,249}, {161,241,249}, {161,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {161,241,249}, {161,241,249}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [OSMFN] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,241,249}, {0,241,249}, {0,241,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
  uint8_t highestLayer = biton32(layer_state);
  switch (highestLayer) {
    case MIRMAIN:
    case JMP:
    case JMPLEFT:
    case JMPRIGHT:
    case MIRNAV:
    case MIRNUM:
    case MIRFN:
    case MIRSYM:
    case MIRMEDIA:
    case MIRMOUSE:
    case OSMNAV:
    case OSMNUM:
    case OSMFN:
      set_layer_color(highestLayer);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    // cancel callum-oakly one-shots with layer keys
    case MO(OSMNUM):
    case MO(OSMNAV):
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    // ignore layer keys
    case MO(OSMNUM):
    case MO(OSMNAV):
    
    // ignore regular mods
    case KC_LSHIFT:
    case KC_LCTRL:
    case KC_LALT:
    case KC_LGUI:

    case KC_RSHIFT:
    case KC_RCTRL:
    case KC_RALT:
    case KC_RGUI:

    // Ignore all one-shot layers to allow stacking one shot layers and mods
    case OSL_JMPL...OSL_FUN:

    // ignore osm keys
    case OS_LSFT:
    case OS_LCTL:
    case OS_LALT:
    case OS_LGUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft = os_up_unqueued;
oneshot_state os_ctrl = os_up_unqueued;
oneshot_state os_lalt = os_up_unqueued;
oneshot_state os_lgui = os_up_unqueued;

oneshot_state os_jmpl = os_up_unqueued;
oneshot_state os_jmpr = os_up_unqueued;

oneshot_state os_navigation = os_up_unqueued;
oneshot_state os_number = os_up_unqueued;
oneshot_state os_symbol = os_up_unqueued;
oneshot_state os_function = os_up_unqueued;
oneshot_state os_media = os_up_unqueued;
oneshot_state os_mouse = os_up_unqueued;


void update_oneshot_layer(
    oneshot_state *state,
    uint16_t mod_or_layer,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    bool isLayer = mod_or_layer >= QK_MOMENTARY  && mod_or_layer <= QK_MOMENTARY_MAX;
    uint8_t layer = mod_or_layer & 0xFF;
    
    if (keycode == trigger) {
        // Trigger key
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                // turn on layer/modifier
                if(isLayer) {
                  layer_on(layer);
                } else {
                  register_code(mod_or_layer);
                }
            }
            *state = os_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
            case os_down_unused:
                // If we didn't use the mod/layer while trigger was held, queue it.
                *state = os_up_queued;
                break;
            case os_down_used:
                // If we did use the mod/layer while trigger was held, unregister it.
                *state = os_up_unqueued;
                if(isLayer) {
                  layer_off(layer);
                } else {
                  unregister_code(mod_or_layer);
                }
                break;
            default:
                break;
            }
        }
    } else {
        // Other keys
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                if(isLayer) {
                  layer_off(layer);
                } else {
                  unregister_code(mod_or_layer);
                }
            }
        } else {
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_down_unused:
                    *state = os_down_used;
                    break;
                case os_up_queued:
                    *state = os_up_unqueued;
                    if(isLayer) {
                      layer_off(layer);
                    } else {
                      unregister_code(mod_or_layer);
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Check for the callum oakley one-shot keys, and update state if other key pressed
  update_oneshot(&os_shft, KC_LSFT, OS_LSFT, keycode, record);
  update_oneshot(&os_ctrl, KC_LCTL, OS_LCTL, keycode, record);
  update_oneshot(&os_lalt, KC_LALT, OS_LALT, keycode, record);
  update_oneshot(&os_lgui, KC_LGUI, OS_LGUI, keycode, record);

  // oneshot layers
  update_oneshot_layer(&os_jmpl, MO(JMPLEFT), OSL_JMPL, keycode, record);
  update_oneshot_layer(&os_jmpr, MO(JMPRIGHT), OSL_JMPR, keycode, record);

  update_oneshot_layer(&os_media, MO(MIRMEDIA), OSL_MEDIA, keycode, record);
  update_oneshot_layer(&os_navigation, MO(MIRNAV), OSL_NAV, keycode, record);
  update_oneshot_layer(&os_mouse, MO(MIRMOUSE), OSL_MOUSE, keycode, record);
  
  update_oneshot_layer(&os_symbol, MO(MIRSYM), OSL_SYM, keycode, record);
  update_oneshot_layer(&os_number, MO(MIRNUM), OSL_NUM, keycode, record);
  update_oneshot_layer(&os_function, MO(MIRFN), OSL_FUN, keycode, record);


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
    case OS_LSFT...OSL_FUN:
      // No need to continue processing
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
