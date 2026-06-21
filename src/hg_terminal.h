#ifndef HG_TERMINAL
#define HG_TERMINAL

#include <stdio.h>

void hg_term_clear_color();

void hg_term_cursor_move(unsigned int x, unsigned y);
void hg_term_hidden_cursor();
void hg_term_visible_cursor();

void hg_term_clear_screen();
void hg_term_enter_screen();
void hg_term_exit_screen();

#endif
