/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define IGNORE_MOD_TAP_INTERRUPT
#undef DEBOUNCE
#define DEBOUNCE 5

#define ONESHOT_TAP_TOGGLE 3

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"z9neG/RMXKN"
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_TERM 15
#define COMBO_VARIABLE_LEN