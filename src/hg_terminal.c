#include "hg_terminal.h"
#include "hg_io.h"

void hg_term_clear_color() {
    hg_io_insert_print_queue("\033[0m");
}

void hg_term_set_color(unsigned int r, unsigned int g, unsigned int b) {
    hg_io_insert_print_queue("\033[48;2;%d;%d;%dm ", r, g, b);
}

void hg_term_cursor_move(unsigned int row, unsigned int col) {
    hg_io_insert_print_queue("\033[%u;%uH", row, col);
}

void hg_term_hidden_cursor() {
    hg_io_insert_print_queue("\033[?25l");
}

void hg_term_visible_cursor() {
    hg_io_insert_print_queue("\033[?25h");
}

void hg_term_clear_screen() {
    hg_io_insert_print_queue("\033[2J\033[H");
}

void hg_term_enter_screen() {
    hg_io_insert_print_queue("\033[?1049h");
}

void hg_term_exit_screen() {
    hg_io_insert_print_queue("\033[?1049l");
}
