#ifndef HG_MAIN
#define HG_MAIN

#include "hg_render.h"

typedef struct {
    HG_Screen *screen;
} HG_Program;

void hg_main_loop(HG_Program *program);
void hg_main(HG_Program *program);

#endif
