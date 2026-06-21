#ifndef HG_RENDER
#define HG_RENDER

#include <stdint.h>

#define HG_RENDER_ROW_SIZE 16
#define HG_RENDER_COL_SIZE 32

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} HG_Pixel;

typedef struct {
    HG_Pixel frame[HG_RENDER_ROW_SIZE][HG_RENDER_COL_SIZE];
} HG_Screen;

void hg_screen_init(HG_Screen *screen, HG_Pixel pixel);
void hg_screen_clear(HG_Screen *screen);

void hg_render_pixel(HG_Pixel *pixel);
void hg_render(HG_Screen *screen);

#endif
