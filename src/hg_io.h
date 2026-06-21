#ifndef HG_IO
#define HG_IO

#include <stdint.h>

#define HG_IO_QUEUE_MAX 65536

typedef struct {
    char buffer[HG_IO_QUEUE_MAX];
    uint16_t length;
} HG_IO_Queue;

void hg_io_init(void);
void hg_io_clear_queue(void);
void hg_io_insert_print_queue(const char *format, ...);
void hg_io_flush_queue(void);

char hg_io_input(void);

#endif
