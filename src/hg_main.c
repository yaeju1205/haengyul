#include "hg_main.h"
#include "hg_io.h"
#include "hg_render.h"
#include "hg_terminal.h"
#include <unistd.h>

void hg_main_loop(HG_Program *program) {
    hg_render(program->screen);

    while (1) {
        char key = hg_io_input();

        if (key <= 0) {
            usleep(1000); 
            continue; 
        }
        else if (key == 'q') {
            break;
        }

        hg_render(program->screen);
    };
}

void hg_main(HG_Program *program) {
    hg_term_hidden_cursor();
    hg_term_enter_screen();
    hg_term_clear_screen();
    hg_io_flush_queue();

    hg_term_raw_mode();

    hg_main_loop(program);

    hg_term_exit_screen();
    hg_term_visible_cursor();
    hg_io_flush_queue();

    hg_term_reset_mode();
}

int main() {
    HG_Pixel pixel;
    // pixel.r = 0;
    // pixel.g = 0;
    // pixel.b = 0;

    HG_Screen screen;
    // hg_screen_init(&screen, pixel);

    HG_Program program;

    program.screen = &screen;

    hg_main(&program);

    return 0;
}
