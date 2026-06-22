#include "hg_terminal.h"
#include "hg_io.h"
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

int g_terminal_rows = 24;
int g_terminal_cols = 80;

struct termios g_original_term;

void hg_term_update_size() {
    struct winsize w;

    if (!(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w))) {
        g_terminal_rows = w.ws_row;
        g_terminal_cols = w.ws_col;
    }
}

void hg_term_save_mode(void) {
    tcgetattr(STDIN_FILENO, &g_original_term);
}

void hg_term_reset_mode(void) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_original_term);
}

void hg_term_raw_mode(void) {
    struct termios term = g_original_term;

    term.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void hg_term_clear_color(void) {
    hg_io_insert_print_queue("\033[0m");
}

void hg_term_set_fg_color(unsigned int r, unsigned int g, unsigned int b) {
    hg_io_insert_print_queue("\033[48;2;%d;%d;%dm ", r, g, b);
}

void hg_term_set_bg_color(unsigned int r, unsigned int g, unsigned int b) {
    hg_io_insert_print_queue("\033[38;2;%d;%d;%dm ", r, g, b);
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
