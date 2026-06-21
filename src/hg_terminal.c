#include "hg_terminal.h"
#include "hg_io.h"
#include <unistd.h>
#include <termios.h>

void hg_term_reset_mode(void) {
    struct termios term;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

void hg_term_raw_mode(void) {
    struct termios term;

    term.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void hg_term_clear_color(void) {
    hg_io_insert_print_queue("\033[0m");
}

void hg_term_set_color(unsigned int r, unsigned int g, unsigned int b) {
    hg_io_insert_print_queue("\033[48;2;%d;%d;%dm ", r, g, b);
}

void hg_term_cursor_move(unsigned int row, unsigned int col) {
    hg_io_insert_print_queue("\033[%u;%uH", row, col);
}

void hg_term_hidden_cursor(void) {
    hg_io_insert_print_queue("\033[?25l");
}

void hg_term_visible_cursor(void) {
    hg_io_insert_print_queue("\033[?25h");
}

void hg_term_clear_screen(void) {
    hg_io_insert_print_queue("\033[2J\033[H");
}

void hg_term_enter_screen(void) {
    hg_io_insert_print_queue("\033[?1049h");
}

void hg_term_exit_screen(void) {
    hg_io_insert_print_queue("\033[?1049l");
}
