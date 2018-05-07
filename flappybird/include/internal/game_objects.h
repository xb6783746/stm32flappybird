
#ifndef FLAPPYBIRD_GAME_OBJECTS_H
#define FLAPPYBIRD_GAME_OBJECTS_H

#include <platform.h>
#include <game_structs.h>

typedef enum {

    Bird, Wall, Bonus
} flappybird_object_type_t;

typedef struct flappybird_bird_s{

    fb_uint8_t bird_number;
    fb_uint8_t hp;

} flappybird_bird_t;

typedef struct flappybird_wall_s{


} flappybird_wall_t;

typedef struct flappybird_object_s flappybird_object_t;

typedef void (*bonus_function)(flappybird_object_t *bird, flappybird_object_t *bonus);

typedef struct flappybird_bonus_s {

    bonus_function apply_bonus;
    fb_uint32_t bonus_time;

} flappybird_bonus_t;

typedef struct flappybird_object_s {

    flappybird_object_type_t type;
    gn_game_object go;

    union {

        flappybird_bird_t bird;
        flappybird_wall_t wall;
        flappybird_bonus_t bonus;
    };

} flappybird_object_t;

#endif //FLAPPYBIRD_GAME_OBJECTS_H
