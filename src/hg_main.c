#include "hg_main.h"
#include "hg_io.h"
#include "hg_render.h"
#include "hg_terminal.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void hg_main_loop(HG_Program *program) {
    while (1) {
        hg_render(program->screen);
        usleep(16666);
    }
}

static void hg_sigint_handler(int sig) {
    (void)sig;

    hg_term_exit_screen();
    hg_io_flush_queue();
exit(0); }

void hg_main(HG_Program *program) {
    signal(SIGINT, hg_sigint_handler);

    hg_term_hidden_cursor();
    hg_term_enter_screen();
    hg_term_clear_screen();
    hg_io_flush_queue();

    hg_main_loop(program);

    hg_term_exit_screen();
    hg_term_visible_cursor();
    hg_io_flush_queue();
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
