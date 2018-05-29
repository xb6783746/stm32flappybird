

#ifndef FLAPPYBIRD_GAME_STRUCTS_H
#define FLAPPYBIRD_GAME_STRUCTS_H

#include <platform.h>

typedef fb_float32_t pe_velocity;

typedef struct gn_point_s {

    fb_float32_t x;
    fb_float32_t y;
} pe_point_t;

typedef struct {

    pe_point_t point;

    fb_uint16_t width;
    fb_uint16_t height;

    pe_velocity vertical_velocity;
    pe_velocity horizontal_velocity;

    fb_bool_t is_static;
} pe_game_object;


#endif //FLAPPYBIRD_GAME_STRUCTS_H
