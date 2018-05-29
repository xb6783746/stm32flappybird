
#ifndef FLAPPYBIRD_GAME_OBJECTS_H
#define FLAPPYBIRD_GAME_OBJECTS_H

#include <platform.h>
#include <game_structs.h>

typedef enum {

    Bird, Wall
} flappybird_object_type_t;

typedef struct flappybird_bird_s{

    fb_uint8_t bird_number;

} flappybird_bird_t;

typedef struct flappybird_wall_s{


} flappybird_wall_t;

typedef struct flappybird_object_s {

    flappybird_object_type_t type;
    pe_game_object go;

    union {

        flappybird_bird_t bird;
        flappybird_wall_t wall;
    };

} flappybird_object_t;

#endif //FLAPPYBIRD_GAME_OBJECTS_H
