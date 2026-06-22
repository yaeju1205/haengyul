#include "hg_render.h"
#include "hg_io.h"
#include "hg_terminal.h"
#include "hg_math.h"
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
}

void hg_screen_clear(HG_Screen *screen) {
    memset(screen, 0, sizeof(HG_Screen));
}

void hg_render_pixel(HG_Pixel *pixel) {
    hg_term_set_fg_color(pixel->r, pixel->g, pixel->b);
    hg_term_set_bg_color(pixel->r, pixel->g, pixel->b);
}

void hg_render_screen(HG_Screen *screen) {
    uint8_t row, col;

    int max_rows = hg_min(HG_RENDER_ROW_SIZE, g_terminal_rows);
    int max_cols = hg_min(HG_RENDER_ROW_SIZE, (g_terminal_cols / 2));

    for (row = 0; row < max_rows; ++row) {
        hg_term_cursor_move(row + 1, 1);

        for (col = 0; col < max_cols; ++col) {
            hg_render_pixel(&screen->frame[row][col]);
        }
    }
}

void hg_render(HG_Screen *screen) {
    hg_term_cursor_move(1, 1);

    hg_render_screen(screen);

    hg_term_clear_color();

    hg_io_flush_queue();
}
