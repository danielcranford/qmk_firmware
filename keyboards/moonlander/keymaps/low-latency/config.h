/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 5

#define ONESHOT_TAP_TOGGLE 3

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"z9neG/vEr3R"
#define RGB_MATRIX_STARTUP_SPD 60

/* See https://www.reddit.com/r/ergodox/comments/q6abnq/how_i_got_1ms_response_times_with_my_moonlander/
Defaults are 8 and 5.
No downside to reducing polling interval that I know of
Reducing debounce can/will lead to chattering
*/

#define USB_POLLING_INTERVAL_MS 1
//#undef DEBOUNCE
//#define DEBOUNCE 1

#define QMK_KEYS_PER_SCAN 4
