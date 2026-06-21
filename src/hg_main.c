#include "hg_main.h"
#include "hg_io.h"
#include "hg_render.h"
#include "hg_terminal.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void hg_main_loop(HG_Program *program) {
    int is_dirty = 1;

    while (1) {
        if (is_dirty) {
            hg_render(program->screen);
            is_dirty = 0;
        }

        char key = hg_io_input();

        if (key <= 0) {
            usleep(1000);
            continue; 
        }
        else if (key == 'q') {
            break;
        }

        is_dirty = 1;
    };
}

static void hg_main_exit(void) {
    hg_term_exit_screen();

    hg_term_exit_screen();
    hg_term_visible_cursor();
    hg_io_flush_queue();

    hg_term_reset_mode();
}

static void hg_sigint_handler(int _sig) {
    hg_main_exit();
    exit(0);
}

void hg_main(HG_Program *program) {
    signal(SIGINT, hg_sigint_handler);

    hg_term_save_mode();
    hg_term_raw_mode();

    hg_term_hidden_cursor();
    hg_term_enter_screen();
    hg_term_clear_screen();
    hg_io_flush_queue();

    hg_main_loop(program);

    hg_main_exit();
}

int main() {
    HG_Pixel pixel;
    pixel.r = 0;
    pixel.g = 0;
    pixel.b = 0;

    HG_Screen screen;
    // hg_screen_init(&screen, pixel);

    HG_Program program;

    program.screen = &screen;

    hg_main(&program);

    return 0;
}
