

#ifndef FLAPPYBIRD_TIMER_SERVICE_H
#define FLAPPYBIRD_TIMER_SERVICE_H

#include <platform.h>

#define TIMER_PERIOD_MSEC 1
#define TIMER_PERIOD_SEC (TIMER_PERIOD_MSEC / 1000.0f)
#define TIMER_FREQUENCY (TIMER_PERIOD_MSEC * 1000)

#define TICKS_TO_SECONDS(t) (t*TIMER_PERIOD_MSEC / 1000.0f)

typedef void (*void_callback)(void);

void timer_service_init(void);

void timer_service_call_periodically(void_callback clb, fb_uint32_t ticks);
void timer_service_delete(void_callback clb);

#endif //FLAPPYBIRD_TIMER_SERVICE_H
