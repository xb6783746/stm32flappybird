

#ifndef FLAPPYBIRD_TIMER_SERVICE_H
#define FLAPPYBIRD_TIMER_SERVICE_H

#include <platform.h>

#define TIMER_PERIOD_MSEC 1
#define TIMER_PERIOD_SEC (TIMER_PERIOD_MSEC / 1000.0f)

#define TICKS_TO_SECONDS(t) (t*TIMER_PERIOD_MSEC / 1000.0f)

typedef void (*void_callback)(void);

void timer_service_call_periodically(void_callback clb, fb_uint8_t ticks);

#endif //FLAPPYBIRD_TIMER_SERVICE_H
