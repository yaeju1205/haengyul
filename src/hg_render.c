#include "hg_render.h"
#include "hg_terminal.h"
#include <stdio.h>
#include <stdint.h>
#include <immintrin.h>
#include <string.h>

void hg_screen_init(HG_Screen *screen, HG_Pixel pixel) {
    uint8_t row, col;

    for (row = 0; row < HG_RENDER_ROW_SIZE; ++row) {
        for (col = 0; col < HG_RENDER_COL_SIZE; ++col) {
            screen->frame[row][col].r = pixel.r;
            screen->frame[row][col].g = pixel.g;
            screen->frame[row][col].b = pixel.b;
        }
    }
} void hg_screen_clear(HG_Screen *screen) {
    memset(screen, 0, sizeof(HG_Screen));
}

void hg_render_pixel(HG_Pixel *pixel) {
    printf("\033[48;2;%d;%d;%dm ", pixel->r, pixel->g, pixel->b);
}

void hg_render(HG_Screen *screen) {
    hg_term_clear_color();

    uint8_t row, col;

    for (row = 0; row < HG_RENDER_ROW_SIZE; ++row) {
        hg_term_cursor_move(row + 1, 1);

        for (col = 0; col < HG_RENDER_COL_SIZE; ++col) {
            hg_render_pixel(&screen->frame[row][col]);
        }
    }

    hg_term_cursor_move(1, 1);
}
