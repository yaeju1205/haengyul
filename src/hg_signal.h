#ifndef HG_SIGNAL
#define HG_SIGNAL

#include <signal.h>

typedef struct {
    sig_atomic_t int_triggered;
    sig_atomic_t windch_triggered;
} HG_SignalStatus;

extern HG_SignalStatus g_signals;

void hg_signal_init(void);

#endif
