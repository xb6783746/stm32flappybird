

#ifndef FLAPPYBIRD_GAME_STRUCTS_H
#define FLAPPYBIRD_GAME_STRUCTS_H

#include <geometric_primitives.h>

typedef fb_float32_t gn_velocity;

typedef struct {

    gl_point_t point;

    fb_uint16_t width;
    fb_uint16_t height;

    gn_velocity vertical_velocity;
    gn_velocity horizontal_velocity;

    fb_bool_t is_static;
} gn_game_object;


#endif //FLAPPYBIRD_GAME_STRUCTS_H
