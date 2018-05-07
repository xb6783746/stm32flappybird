
#ifndef FLAPPYBIRD_OBJECT_BUFFER_H
#define FLAPPYBIRD_OBJECT_BUFFER_H

#include <game_structs.h>
#include <physics_engine.h>
#include <graphics_engine.h>
#include <internal/game_objects.h>

#define GAME_OBJECT_BUFFER_CAPACITY 100

typedef struct fb_buffer_entry_s{

    fb_uint8_t is_free;
    flappybird_object_t obj;

} fb_buffer_entry_t;


extern fb_buffer_entry_t game_objects[GAME_OBJECT_BUFFER_CAPACITY];

void fb_object_buffer_init(void);

void fb_object_buffer_release(gn_game_object *go);

flappybird_object_t* fb_object_buffer_get_object(flappybird_object_type_t type);
#endif //FLAPPYBIRD_OBJECT_BUFFER_H
