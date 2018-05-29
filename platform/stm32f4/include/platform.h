
#ifndef FLAPPYBIRD_PLATFORM_H
#define FLAPPYBIRD_PLATFORM_H

#include <stdint.h>

#define FB_FALSE 0
#define FB_TRUE !FB_FALSE
#define FB_NULL 0

typedef uint8_t fb_uint8_t;
typedef int8_t fb_int8_t;

typedef uint16_t fb_uint16_t;
typedef int16_t fb_int16_t;

typedef uint32_t fb_uint32_t;
typedef int32_t fb_int32_t;

typedef uint64_t fb_uint64_t;
typedef int64_t fb_int64_t;

typedef float fb_float32_t;
typedef double fb_float64_t;

typedef uint8_t fb_bool_t;

#endif //FLAPPYBIRD_PLATFORM_H
