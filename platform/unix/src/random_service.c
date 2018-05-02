
#include <random_service.h>
#include <stdlib.h>

fb_float32_t fb_random(){

    return (fb_float32_t) (rand() / (fb_float32_t)RAND_MAX);
}

fb_uint32_t fb_random_between(fb_uint32_t from, fb_uint32_t to){

    return (fb_uint32_t) (rand() % (to - from) + from);
}