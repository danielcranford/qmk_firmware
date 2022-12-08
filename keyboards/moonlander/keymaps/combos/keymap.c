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

#define ALT_APP MT(MOD_LALT, KC_APPLICATION)
#define CTL_ESC MT(MOD_LCTL, KC_ESCAPE)

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define CTL_D MT(MOD_LCTL, KC_D)
#define SFT_F MT(MOD_LSFT, KC_F)
#define SFT_J MT(MOD_LSFT, KC_J)
#define CTL_K MT(MOD_LCTL, KC_K)
#define ALT_L MT(MOD_LALT, KC_L)
#define GUI_SCN MT(MOD_LGUI, KC_SCOLON)
#define MED_ESC LT(MIRMEDIA,KC_ESCAPE)
#define FUN_DEL LT(MIRFN,KC_DELETE)
#define NAV_BSP LT(MIRNAV,KC_BSPACE)
#define MOU_TAB LT(MIRMOUSE,KC_TAB)
#define SYM_ENT LT(MIRSYM,KC_ENTER)
#define NUM_SPC LT(MIRNUM,KC_SPACE)

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

  LL_CUR,
  LL_OPP,
  LL_CLR,
};

enum layers {
  DEFAULT,
  CMBMAIN,
  OSMMAIN,
  MIRMAIN,
  THE1,
  THE1HRM,
  THE1SFT,
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

/*enum taps {
  LR_DEF,
  LR_MIR,
  LR_FUN,
  LR_NUM,
  LR_SYM,
  LR_MED,
  LR_NAV,
  LR_MOU,
}*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT] = LAYOUT_moonlander(
    KC_EQUAL,       KC_1,              KC_2,           KC_3,           KC_4,           KC_5,           TG(MIRMAIN),                 TG(THE1),    KC_6,                    KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    SH_TG,          KC_Q,              KC_W,           KC_E,           KC_R,           KC_T,           TG(CMBMAIN),                 TG(OSMMAIN), KC_Y,                    KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,      
    SH_OS,          KC_A,              KC_S,           KC_D,           KC_F,           KC_G,           TG(MEDIA),                   TG(JMP),     KC_H,                    KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,       
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
    KC_EQUAL,             KC_1,                KC_2,               KC_3,               KC_4,                   KC_5,           TG(MIRMAIN),    TG(THE1),       KC_6,           KC_7,                KC_8,               KC_9,               KC_0,                    KC_MINUS,
    KC_TRANSPARENT,       KC_Q,                KC_W,               KC_E,               KC_R,                   KC_T,           KC_TRANSPARENT, KC_TRANSPARENT, KC_Y,           KC_U,                KC_I,               KC_O,               KC_P,                    KC_BSLASH, 
    KC_TRANSPARENT,       GUI_A,               ALT_S,              CTL_D,              SFT_F,                  KC_G,           KC_TRANSPARENT, KC_TRANSPARENT, KC_H,           SFT_J,               CTL_K,              ALT_L,              GUI_SCN,                 KC_QUOT, 
    KC_TRANSPARENT,       KC_Z,                KC_X,               KC_C,               KC_V,                   KC_B,                                           KC_N,           KC_M,                KC_COMMA,           KC_DOT,             KC_SLASH,                KC_TRANSPARENT, 
    KC_TRANSPARENT,       KC_TRANSPARENT,      KC_TRANSPARENT,     KC_TRANSPARENT,     MED_ESC,                KC_TRANSPARENT,                                 KC_TRANSPARENT, FUN_DEL,             KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,          KC_TRANSPARENT, 
    NAV_BSP,              MOU_TAB,             KC_TRANSPARENT,     KC_TRANSPARENT,     SYM_ENT,                NUM_SPC
  ),
  [THE1] = LAYOUT_moonlander(
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	
	KC_TRANSPARENT,	KC_K,	KC_M,	KC_L,	KC_U,	KC_QUES,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_V,	KC_D,	KC_R,	KC_QUOTE,	KC_Q,	KC_TRANSPARENT,	
	KC_TRANSPARENT,	KC_A,	KC_T,	KC_H,	KC_E,	KC_DOT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_C,	KC_S,	KC_N,	KC_O,	KC_I,	KC_TRANSPARENT,	
	MO(THE1SFT),	KC_Z,	KC_P,	KC_F,	KC_J,	KC_COMMA,	KC_B,	KC_G,	KC_W,	KC_X,	KC_Y,	MO(THE1SFT),	
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT
	),
  [THE1HRM]	=	LAYOUT_moonlander(
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	
	KC_TRANSPARENT,	KC_K,	KC_M,	KC_L,	KC_U,	KC_QUES,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_V,	KC_D,	KC_R,	KC_QUOTE,	KC_Q,	KC_TRANSPARENT,	
	KC_TRANSPARENT,	MT(MOD_LGUI,	KC_A),MT(MOD_LALT,	KC_T),MT(MOD_LCTL,	KC_H),LT(THE1SFT,KC_E),	KC_DOT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_C,	LT(THE1SFT,KC_S),	MT(MOD_RCTL,	KC_N),MT(MOD_RALT,	KC_O),MT(MOD_RGUI,	KC_I),KC_TRANSPARENT,	
	KC_TRANSPARENT,	KC_Z,	KC_P,	KC_F,	KC_J,	KC_COMMA,	KC_B,	KC_G,	KC_W,	KC_X,	KC_Y,	KC_TRANSPARENT,	
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT
	),
  [THE1SFT]	=	LAYOUT_moonlander(
	KC_TRANSPARENT,	KC_EXLM,	KC_AT,	KC_HASH,	KC_DLR,	KC_PERC,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_TRANSPARENT,	
	KC_TRANSPARENT,	LSFT(KC_K),	LSFT(KC_M),	LSFT(KC_L),	LSFT(KC_U),	KC_EXLM,	KC_TRANSPARENT,	KC_TRANSPARENT,	LSFT(KC_V),	LSFT(KC_D),	LSFT(KC_R),	KC_DQUO,	LSFT(KC_Q),	KC_TRANSPARENT,	
	KC_TRANSPARENT,	LSFT(KC_A),	LSFT(KC_T),	LSFT(KC_H),	LSFT(KC_E),	KC_COLN,	KC_TRANSPARENT,	KC_TRANSPARENT,	LSFT(KC_C),	LSFT(KC_S),	LSFT(KC_N),	LSFT(KC_O),	LSFT(KC_I),	KC_TRANSPARENT,	
	KC_TRANSPARENT,	LSFT(KC_Z),	LSFT(KC_P),	LSFT(KC_F),	LSFT(KC_J),	KC_SCOLON,	LSFT(KC_B),	LSFT(KC_G),	LSFT(KC_W),	LSFT(KC_X),	LSFT(KC_Y),	KC_TRANSPARENT,	
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LL_CLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_INSERT,      KC_HOME,        KC_UP,          KC_END,         KC_PGUP,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPSLOCK,    KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDOWN,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LL_OPP,         LL_CUR,     KC_TRANSPARENT,                                 LCTL(KC_Y),     KC_PC_PASTE,    KC_PC_COPY,     KC_PC_CUT,      KC_PC_UNDO,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_SPACE
  ),
  [MIRNUM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LBRACKET,    KC_7,           KC_8,           KC_9,           KC_RBRACKET,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LL_CLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_QUOTE,       KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_BSLASH,                                      KC_TRANSPARENT, LL_CUR,         LL_OPP,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_0,           KC_MINUS,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRFN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PSCREEN,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LL_CLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_SCROLLLOCK,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_PAUSE,                                       KC_TRANSPARENT, LL_CUR,         LL_OPP,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_APPLICATION, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_BSPACE,      KC_TAB,         KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRSYM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LL_CLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_DQUO,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_PIPE,                                        KC_TRANSPARENT, LL_CUR,         LL_OPP,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_RPRN,        KC_UNDS,        KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MIRMEDIA] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LL_CLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LL_OPP,         LL_CUR,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE
  ),
  [MIRMOUSE] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LL_CLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_MS_WH_UP,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LL_OPP,         LL_CUR,         KC_TRANSPARENT,                                 LCTL(KC_Y),     KC_PC_PASTE,    KC_PC_COPY,     KC_PC_CUT,      KC_PC_UNDO,     KC_TRANSPARENT, 
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

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();

  // Disable combos by default
  combo_disable();

  // Turn on MIRMAIN by default
  layer_on(MIRMAIN);
}

/* RGB LED map appears to number keys thusly
0 5 10 15 20 25 29         65 61 56 51 46 41 36
1 6 11 16 21 26 30         66 62 57 52 47 42 37
2 7 12 17 22 27 31         67 63 58 53 48 43 38
3 8 13 18 23 28               64 59 54 49 44 39
4 9 14 19 24    35         71    60 55 50 45 40
             32 33 34   70 69 68
 */
// Color definations from Oryx
#define HSV_PINKMAN 210,241,249
#define HSV_DANGER 0,241,249
#define HSV_MAGIC_INK 161,241,249
#define HSV_GALACTIC_EMERALD 89,241,249
#define HSV_ELECTRIC_CYAN 131,241,249
#define HSV_LAHN_YELLOW 42,241,249


// Reuse simple color names already defined in color.h
#undef HSV_RED
#undef HSV_BLUE
#undef HSV_GREEN
#undef HSV_CYAN

#define HSV_MGNTA HSV_PINKMAN
#define HSV_YLLOW HSV_LAHN_YELLOW
#define HSV_RED HSV_DANGER
#define HSV_BLUE HSV_MAGIC_INK
#define HSV_GREEN HSV_GALACTIC_EMERALD
#define HSV_CYAN HSV_ELECTRIC_CYAN
#define HSV______ HSV_BLACK

#define LEDLAYOUT(\
a00,a05,a10,a15,a20,a25,a29,         a65,a61,a56,a51,a46,a41,a36,\
a01,a06,a11,a16,a21,a26,a30,         a66,a62,a57,a52,a47,a42,a37,\
a02,a07,a12,a17,a22,a27,a31,         a67,a63,a58,a53,a48,a43,a38,\
a03,a08,a13,a18,a23,a28,                 a64,a59,a54,a49,a44,a39,\
a04,a09,a14,a19,a24,    a35,         a71,    a60,a55,a50,a45,a40,\
                    a32,a33,a34, a70,a69,a68)\
{\
{a00},{a01},{a02},{a03},{a04},{a05},{a06},{a07},{a08},{a09},\
{a10},{a11},{a12},{a13},{a14},{a15},{a16},{a17},{a18},{a19},\
{a20},{a21},{a22},{a23},{a24},{a25},{a26},{a27},{a28},{a29},\
{a30},{a31},{a32},{a33},{a34},{a35},{a36},{a37},{a38},{a39},\
{a40},{a41},{a42},{a43},{a44},{a45},{a46},{a47},{a48},{a49},\
{a50},{a51},{a52},{a53},{a54},{a55},{a56},{a57},{a58},{a59},\
{a60},{a61},{a62},{a63},{a64},{a65},{a66},{a67},{a68},{a69},\
{a70},{a71},}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [MIRMAIN] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV_WHITE,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                                           HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV_MGNTA,          HSV______,                       HSV______,          HSV_RED,HSV______,HSV______,HSV______,HSV______,
                                                        HSV_CYAN, HSV_YLLOW,HSV______,   HSV______,HSV_GREEN,HSV_BLUE
    ),

    [JMP] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                                           HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV_WHITE,          HSV______,                       HSV______,          HSV_WHITE,HSV______,HSV______,HSV______,HSV______,
                                                        HSV______,HSV______,HSV______,   HSV______,HSV______,HSV______
    ),

    [JMPLEFT] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                                           HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,          HSV______,                       HSV______,          HSV_RED  ,HSV______,HSV______,HSV______,HSV______,
                                                        HSV______,HSV______,HSV______,   HSV______,HSV_GREEN,HSV_BLUE
    ),

    [JMPRIGHT] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                                           HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV_MGNTA,          HSV______,                       HSV______,          HSV_RED  ,HSV______,HSV______,HSV______,HSV______,
                                                        HSV_CYAN, HSV_YLLOW,HSV______,   HSV______,HSV_GREEN,HSV_BLUE
    ),

   [MIRNAV] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV______,
      HSV______,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV______,HSV______,                       HSV______,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                                           HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,          HSV______,                       HSV______,          HSV_CYAN ,HSV______,HSV______,HSV______,HSV______,
                                                        HSV_CYAN, HSV______,HSV______,   HSV______,HSV_CYAN,HSV_CYAN
    ),

   [MIRNUM] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV______,                       HSV______,HSV______,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV______,
      HSV______,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,                                           HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV_BLUE ,          HSV______,                       HSV______,          HSV______,HSV______,HSV______,HSV______,HSV______,
                                                        HSV_BLUE ,HSV_BLUE ,HSV______,   HSV______,HSV______,HSV_BLUE
    ),

   [MIRFN] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV______,                       HSV______,HSV______,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV______,
      HSV______,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,                                           HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV_RED  ,          HSV______,                       HSV______,          HSV_RED  ,HSV______,HSV______,HSV______,HSV______,
                                                        HSV_RED  ,HSV_RED  ,HSV______,   HSV______,HSV______,HSV______
    ),
   
   [MIRSYM] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_GREEN,HSV_GREEN,HSV_GREEN,HSV_GREEN,HSV_GREEN,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_GREEN,HSV_GREEN,HSV_GREEN,HSV_GREEN,HSV_GREEN,HSV______,                       HSV______,HSV______,HSV_GREEN,HSV_GREEN,HSV_GREEN,HSV_GREEN,HSV______,
      HSV______,HSV_GREEN,HSV_GREEN,HSV_GREEN,HSV_GREEN,HSV_GREEN,                                           HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV_GREEN,          HSV______,                       HSV______,          HSV______,HSV______,HSV______,HSV______,HSV______,
                                                        HSV_GREEN,HSV_GREEN,HSV______,   HSV______,HSV_GREEN,HSV______
    ),

   [MIRMEDIA] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_MGNTA,HSV_MGNTA,HSV_MGNTA,HSV_MGNTA,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                                           HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV_MGNTA,          HSV______,                       HSV______,          HSV_MGNTA,HSV______,HSV______,HSV______,HSV______,
                                                        HSV______,HSV______,HSV______,   HSV______,HSV_MGNTA,HSV_MGNTA
    ),

   [MIRMOUSE] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV______,
      HSV______,HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV______,HSV______,                       HSV______,HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                                           HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV_YLLOW,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,          HSV______,                       HSV______,          HSV_YLLOW,HSV______,HSV______,HSV______,HSV______,
                                                        HSV______,HSV_YLLOW,HSV______,   HSV______,HSV_YLLOW,HSV_YLLOW
    ),

   [OSMNAV] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV______,
      HSV______,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV______,HSV______,                       HSV______,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                                           HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV_CYAN ,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV______,          HSV______,                       HSV_WHITE,          HSV_WHITE,HSV______,HSV______,HSV______,HSV______,
                                                        HSV______,HSV______,HSV______,   HSV______,HSV______,HSV______
    ),

   [OSMNUM] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV______,                       HSV______,HSV______,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV______,
      HSV______,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,HSV_BLUE ,                                           HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV_WHITE,          HSV_WHITE,                       HSV______,          HSV______,HSV______,HSV______,HSV______,HSV______,
                                                        HSV_BLUE ,HSV_BLUE ,HSV______,   HSV______,HSV______,HSV______
    ),

   [OSMFN] = LEDLAYOUT(
      HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV______,                       HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV______,                       HSV______,HSV______,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV_WHITE,HSV______,
      HSV______,HSV______,HSV_RED  ,HSV_RED  ,HSV_RED  ,HSV_RED  ,                                           HSV______,HSV______,HSV______,HSV______,HSV______,HSV______,
      HSV______,HSV______,HSV______,HSV______,HSV_RED  ,          HSV______,                       HSV______,          HSV______,HSV______,HSV______,HSV______,HSV______,
                                                        HSV______,HSV______,HSV______,   HSV______,HSV______,HSV______
    ),

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
  if (keyboard_config.disable_layer_led) { return; }
  // Include default layer in determination of which layer we are on
  layer_state_t layers = layer_state | default_layer_state;
  uint8_t highestLayer = biton32(layers);
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

static bool layerLocked = false;
static uint8_t lockedLayer = 0;

static uint8_t oppositeOf(uint8_t layer) {
  switch (layer)
  {
  case MIRMEDIA: return MIRFN;
  case MIRNAV: return MIRNUM;
  case MIRMOUSE: return MIRSYM;
  case MIRSYM: return MIRMOUSE;
  case MIRNUM: return MIRNAV;
  case MIRFN: return MIRMEDIA;
  default: return layer;
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
        rgblight_mode(1 /* RGBLIGHT_MODE_STATIC_LIGHT */);
        rgblight_sethsv(0,255,255);
      }
      return false;

    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1 /* RGBLIGHT_MODE_STATIC_LIGHT */);
        rgblight_sethsv(86,255,128);
      }
      return false;

    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1 /* RGBLIGHT_MODE_STATIC_LIGHT */);
        rgblight_sethsv(172,255,255);
      }
      return false;

    case OS_LSFT...OSL_FUN:
      // No need to continue processing
      return false;

    case LL_CLR:
      if (record->event.pressed) {
        layerLocked = false;
        layer_off(lockedLayer);
        lockedLayer = 0;        
      }
      
      return false;

    case LL_OPP: // fallthrough
    case LL_CUR:
      if (record->event.pressed) {
        // Note: do not want to mess with default_layer here
        // no getter for layer state, use extern ref to access
        uint8_t layer = biton32(layer_state); 
        if(keycode == LL_OPP) {
          layer = oppositeOf(layer);
        }
        // Save locked layer
        lockedLayer = layer;
        layerLocked = true;
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


  S_1,
  S_2,
  S_3,
  S_4,
  S_5,

  S_Q,
  S_W,
  S_E,
  S_R,
  S_T,

  S_A,
  S_S,
  S_D,
  S_F,
  S_G,

  S_Z,
  S_X,
  S_C,
  S_V,
  S_B,

  S_6,
  S_7,
  S_8,
  S_9,
  S_0,

  S_Y,
  S_U,
  S_I,
  S_O,
  S_P,

  S_H,
  S_J,
  S_K,
  S_L,
  S_SCLN,

  S_N,
  S_M,
  S_CMA,
  S_DOT,
  S_SLS,

  // Outer pinky Shift combos
  S_EQL,
  S_MIN,
  S_BSL,
  S_QOT,

  // Try CAPSWRD
  SS_CW,

  COMBO_LENGTH
};



#define KEYS(...) (uint16_t[]){__VA_ARGS__, COMBO_END}

/* 
Note, this method  of filling the combo array breaks on AVR (which the Moonlander
does not use) since process_combos.c assumed the keys list are in PROGMEM which cannot 
be used with the compound literal arrays used by the KEYS macro
*/
combo_t key_combos[COMBO_LENGTH] = {
  // Home row only combos for mods
  [ESC_F]   = COMBO(KEYS(KC_ESCAPE, KC_F), KC_LSHIFT),
  [ESC_D]    = COMBO(KEYS(KC_ESCAPE, KC_D), KC_LCTRL),
  [ESC_S]     = COMBO(KEYS(KC_ESCAPE, KC_S), KC_LALT),
  [ESC_A]     = COMBO(KEYS(KC_ESCAPE, KC_A), KC_LGUI),

  // Combos for thumb keys. 
  [ESC_V] = COMBO(KEYS(KC_V, KC_ESCAPE), MO(MIRMEDIA)),
  [BSPACE_V] = COMBO(KEYS(KC_V, KC_BSPACE), MO(MIRNAV)),
  [TAB_V] = COMBO(KEYS(KC_V, KC_TAB), MO(MIRMOUSE)),

  // Home row only combos for mods
  [DEL_J]   = COMBO(KEYS(KC_DEL, KC_J), KC_LSHIFT),
  [DEL_K]    = COMBO(KEYS(KC_DEL, KC_J), KC_LCTRL),
  [DEL_L]     = COMBO(KEYS(KC_DEL, KC_L), KC_LALT),
  [DEL_SCOLON]  = COMBO(KEYS(KC_DEL, KC_SCOLON), KC_LGUI),

  // Combos for thumb keys. 
  [DEL_M]    = COMBO(KEYS(KC_M, KC_DEL), MO(MIRFN)),
  [SPC_M]   = COMBO(KEYS(KC_M, KC_SPACE), MO(MIRNUM)),
  [ENTR_M] = COMBO(KEYS(KC_M, KC_ENTER), MO(MIRSYM)),


  // Shift combos
  [S_1] = COMBO(KEYS(KC_1, SFT_J), LSFT(KC_1)),
  [S_2] = COMBO(KEYS(KC_2, SFT_J), LSFT(KC_2)),
  [S_3] = COMBO(KEYS(KC_3, SFT_J), LSFT(KC_3)),
  [S_4] = COMBO(KEYS(KC_4, SFT_J), LSFT(KC_4)),
  [S_5] = COMBO(KEYS(KC_5, SFT_J), LSFT(KC_5)),

  [S_Q] = COMBO(KEYS(KC_Q, SFT_J), LSFT(KC_Q)),
  [S_W] = COMBO(KEYS(KC_W, SFT_J), LSFT(KC_W)),
  [S_E] = COMBO(KEYS(KC_E, SFT_J), LSFT(KC_E)),
  [S_R] = COMBO(KEYS(KC_R, SFT_J), LSFT(KC_R)),
  [S_T] = COMBO(KEYS(KC_T, SFT_J), LSFT(KC_T)),

  [S_A] = COMBO(KEYS(MT(MOD_LGUI, KC_A), SFT_J), LSFT(KC_A)),
  [S_S] = COMBO(KEYS(MT(MOD_LALT, KC_S), SFT_J), LSFT(KC_S)),
  [S_D] = COMBO(KEYS(MT(MOD_LCTL, KC_D), SFT_J), LSFT(KC_D)),
  //[S_F] = COMBO(KEYS(SFT_F, SFT_J), LSFT(KC_F)),
  [S_G] = COMBO(KEYS(KC_G, SFT_J), LSFT(KC_G)),

  [S_Z] = COMBO(KEYS(KC_Z, SFT_J), LSFT(KC_Z)),
  [S_X] = COMBO(KEYS(KC_X, SFT_J), LSFT(KC_X)),
  [S_C] = COMBO(KEYS(KC_C, SFT_J), LSFT(KC_C)),
  [S_V] = COMBO(KEYS(KC_V, SFT_J), LSFT(KC_V)),
  [S_B] = COMBO(KEYS(KC_B, SFT_J), LSFT(KC_B)),

  [S_6] = COMBO(KEYS(KC_6, SFT_F), LSFT(KC_6)),
  [S_7] = COMBO(KEYS(KC_7, SFT_F), LSFT(KC_7)),
  [S_8] = COMBO(KEYS(KC_8, SFT_F), LSFT(KC_8)),
  [S_9] = COMBO(KEYS(KC_9, SFT_F), LSFT(KC_9)),
  [S_0] = COMBO(KEYS(KC_0, SFT_F), LSFT(KC_0)),

  [S_Y] = COMBO(KEYS(KC_Y, SFT_F), LSFT(KC_Y)),
  [S_U] = COMBO(KEYS(KC_U, SFT_F), LSFT(KC_U)),
  [S_I] = COMBO(KEYS(KC_I, SFT_F), LSFT(KC_I)),
  [S_O] = COMBO(KEYS(KC_O, SFT_F), LSFT(KC_O)),
  [S_P] = COMBO(KEYS(KC_P, SFT_F), LSFT(KC_P)),

  [S_H] = COMBO(KEYS(KC_H, SFT_F), LSFT(KC_H)),
  //[S_J] = COMBO(KEYS(SFT_J, SFT_F), LSFT(KC_J)),
  [S_K] = COMBO(KEYS(MT(MOD_LCTL, KC_K), SFT_F), LSFT(KC_K)),
  [S_L] = COMBO(KEYS(MT(MOD_LALT, KC_L), SFT_F), LSFT(KC_L)),
  [S_SCLN] = COMBO(KEYS(MT(MOD_LGUI, KC_SCLN), SFT_F), LSFT(KC_SCLN)),

  [S_N] = COMBO(KEYS(KC_N, SFT_F), LSFT(KC_N)),
  [S_M] = COMBO(KEYS(KC_M, SFT_F), LSFT(KC_M)),
  [S_CMA] = COMBO(KEYS(KC_COMMA, SFT_F), LSFT(KC_COMMA)),
  [S_DOT] = COMBO(KEYS(KC_DOT, SFT_F), LSFT(KC_DOT)),
  [S_SLS] = COMBO(KEYS(KC_SLASH, SFT_F), LSFT(KC_SLASH)),

  [S_EQL] = COMBO(KEYS(KC_EQL, SFT_J), LSFT(KC_EQL)),
  [S_MIN] = COMBO(KEYS(KC_MINUS, SFT_F), LSFT(KC_MINUS)),
  [S_BSL] = COMBO(KEYS(KC_BSLS, SFT_F), LSFT(KC_BSLS)),
  [S_QOT] = COMBO(KEYS(KC_QUOT, SFT_F), LSFT(KC_QUOT)),

  [SS_CW] = COMBO(KEYS(SFT_J, SFT_F), CAPS_WORD),
};

uint16_t COMBO_LEN = COMBO_LENGTH;


// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  // Enable combos only when combo layer is one of the active layers
  if(layer_state_cmp(state, CMBMAIN) || layer_state_cmp(state, MIRMAIN)) {
    combo_enable();
  } else {
    combo_disable();
  }

  if(layerLocked != 0) {
    // Update state to ensure lockedLayer stays on
    state |= ((layer_state_t)1 << lockedLayer);
  }
  return state;
}

void oneshot_mods_changed_user(uint8_t mods) {
}
void oneshot_layer_changed_user(uint8_t layer) {
}
