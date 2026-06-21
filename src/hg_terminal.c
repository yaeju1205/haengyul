#include "hg_terminal.h"
#include <stdio.h>

void hg_term_clear_color() {
    printf("\033[0m");
    fflush(stdout);
}

void hg_term_cursor_move(unsigned int row, unsigned int col) {
    printf("\033[%u;%uH", row, col);
    fflush(stdout);
}

void hg_term_hidden_cursor() {
    printf("\033[?25l");
    fflush(stdout);
}

void hg_term_visible_cursor() {
    printf("\033[?25h");
    fflush(stdout);
}

void hg_term_clear_screen() {
    printf("\033[2J\033[H");
    fflush(stdout);
}

void hg_term_enter_screen() {
    printf("\033[?1049h");
    hg_term_clear_screen();
    fflush(stdout);
}

void hg_term_exit_screen() {
    printf("\033[?1049l");
    fflush(stdout);
}
