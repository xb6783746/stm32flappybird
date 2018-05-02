
#ifndef FLAPPYBIRD_GRAPHICS_PRIMITIVES_H
#define FLAPPYBIRD_GRAPHICS_PRIMITIVES_H

#include <platform.h>

typedef struct gl_color_s{

    fb_uint8_t red;
    fb_uint8_t green;
    fb_uint8_t blue;
} gl_color_t;

typedef struct gl_point_s {

    fb_float32_t x;
    fb_float32_t y;
} gl_point_t;

typedef struct gl_rectangle_s {

    gl_point_t point;

    fb_uint16_t width;
    fb_uint16_t height;

    fb_uint8_t border_size;

    gl_color_t color;

} gl_rectangle_t;

typedef struct gl_circle_s {

    gl_point_t point;

    fb_uint16_t radius;

    fb_uint8_t border_size;

    gl_color_t color;

} gl_circle_t;

typedef struct gl_filled_rectangle_s {

    gl_point_t point;

    fb_uint16_t width;
    fb_uint16_t height;

    gl_color_t color;

} gl_filled_rectangle_t;

typedef struct gl_filled_circle_s {

    gl_point_t point;

    fb_uint16_t radius;

    gl_color_t color;

} gl_filled_circle_t;

#endif //FLAPPYBIRD_GRAPHICS_PRIMITIVES_H
