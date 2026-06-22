#include "hg_signal.h"
#include <signal.h>
#include <stddef.h>

#define trigger_signal(signal) signal = 1

HG_SignalStatus g_signals = {
    0,
    0
};

static void hg_generic_handler(int sig) {
    switch (sig) {
        case SIGINT:
            trigger_signal(g_signals.int_triggered);
            break;
        case SIGWINCH:
            trigger_signal(g_signals.windch_triggered);
            break;
    }
}

void hg_signal_init(void) {
    struct sigaction sa;
    sa.sa_handler = hg_generic_handler;

    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGWINCH, &sa, NULL);
}
