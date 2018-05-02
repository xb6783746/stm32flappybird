
#include <random_service.h>
#include <stdlib.h>

fb_uint32_t fb_random(){

    return (fb_uint32_t) (rand() / RAND_MAX);
}