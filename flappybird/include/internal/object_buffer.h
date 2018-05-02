
#ifndef FLAPPYBIRD_OBJECT_BUFFER_H
#define FLAPPYBIRD_OBJECT_BUFFER_H

#include <game_structs.h>
#include <physics_engine.h>
#include <graphics_engine.h>


#define GAME_OBJECT_BUFFER_CAPACITY 100

void flappybird_object_buffer_init(void);

void flappybird_object_buffer_release(gn_game_object *go);

gn_game_object* flappybird_object_buffer_get_game_object(void);

#endif //FLAPPYBIRD_OBJECT_BUFFER_H
