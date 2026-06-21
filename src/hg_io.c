#include "hg_io.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

static HG_IO_Queue g_io_queue;

void hg_io_init(void) {
    hg_io_clear_queue();
}

void hg_io_clear_queue(void) {
    g_io_queue.length = 0;
    g_io_queue.buffer[0] = '\0';
}

void hg_io_insert_print_queue(const char *format, ...) {
    va_list args;
    va_start(args, format);

    size_t remaining = HG_IO_QUEUE_MAX - g_io_queue.length;

    int written = vsnprintf(g_io_queue.buffer + g_io_queue.length, remaining, format, args);

    if (written > 0 && (size_t)written < remaining) {
        g_io_queue.length += written;
    }

    va_end(args);
}

void hg_io_flush_queue(void) {
    if (g_io_queue.length == 0)
        return;

    write(STDOUT_FILENO, g_io_queue.buffer, g_io_queue.length);

    hg_io_clear_queue();
}

char hg_io_input(void) {
    char ch;
    if (read(STDIN_FILENO, &ch, 1) <= 0)
        return -1;

    return ch;
}
