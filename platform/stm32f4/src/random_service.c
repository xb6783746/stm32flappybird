
#include <random_service.h>

#define A 106
#define C 1283
#define M 6075

static fb_uint32_t x = 7;

fb_float32_t fb_random(){

    x = (A * x + C) % M;

    return (fb_float32_t)x / M;
}

fb_uint32_t fb_random_between(fb_uint32_t from, fb_uint32_t to){

    return (fb_uint32_t) (fb_random() * (to - from) + from);
}