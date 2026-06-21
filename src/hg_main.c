#include "hg_main.h"
#include "hg_render.h"
#include "hg_terminal.h"
#include <signal.h>
#include <stdlib.h>

void hg_main_loop(HG_Program *program) {
    while (1) {
        hg_render(program->screen);
    }
}

static void hg_sigint_handler(int sig) {
    (void)sig;

    hg_term_exit_screen();
    exit(0);
}

void hg_main(HG_Program *program) {
    signal(SIGINT, hg_sigint_handler);

    hg_term_hidden_cursor();
    hg_term_enter_screen();
    hg_main_loop(program);
    hg_term_exit_screen();
    hg_term_visible_cursor();
}

int main() {
    HG_Pixel pixel;
    pixel.r = 255;
    pixel.g = 0;
    pixel.b = 0;

    HG_Screen screen;
    hg_screen_init(&screen, pixel);

    HG_Program program;

    program.screen = &screen;

    hg_main(&program);

    return 0;
}
