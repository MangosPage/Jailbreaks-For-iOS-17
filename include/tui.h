#ifndef TUI_H
#define TUI_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <newt.h>
#include <paleinfo.h>

#define WIDTH 76
#define HEIGHT 19

#define PI_LOG_COLOR NEWT_COLORSET_CUSTOM(0)
#define PI_STEP_CURRENT NEWT_COLORSET_CUSTOM(1)
#define PI_STEP_OTHER NEWT_COLORSET_CUSTOM(2)

#define CHECKBOX_STATE(flags, opt) (flags & opt) != 0 ? '*' : ' '

typedef enum tui_screens {
    ERROR_SCREEN = -1,
    EXIT_SCREEN = 0,
    MAIN_SCREEN = 1,
    OPTIONS_SCREEN = 2,
    ENTER_DFU_SCREEN = 3,
    JAILBREAKING_SCREEN = 4,
    ENTER_RECOVERY_SCREEN = 5
} tui_screen_t;

typedef struct bitfield_checkbox_info {
    uint64_t* flags_p;
    uint64_t opt;
} tui_bit_info_t;

tui_screen_t tui_screen_main(void);
tui_screen_t tui_screen_options(void);
tui_screen_t tui_screen_enter_recovery(void);
tui_screen_t tui_screen_enter_dfu(void);
tui_screen_t tui_screen_jailbreak(void);

int redraw_screen(void);


#endif
