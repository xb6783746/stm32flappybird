

#ifndef FLAPPYBIRD_PHYSICS_ENGINE_H
#define FLAPPYBIRD_PHYSICS_ENGINE_H

#include <game_structs.h>

#define PHYS_ENGINE_OBJECT_BUFFER_CAPACITY 15

typedef void (*pe_collision_callback)(pe_game_object *go1, pe_game_object *go2);
typedef void (*pe_object_deleted_callback)(pe_game_object *go);

typedef struct pe_settings_s {

    pe_collision_callback on_collision;
    pe_object_deleted_callback on_object_deleted;

    fb_uint16_t screen_width;
    fb_uint16_t screen_height;

    fb_float32_t gravity;

    fb_float32_t phys_cycle_s;
} pe_settings_t;

void phys_engine_init(pe_settings_t settings);

void phys_engine_add_object(pe_game_object *obj);
void phys_engine_set_gravity(fb_float32_t gravity);

void phys_engine_next(void);

void phys_engine_reset(void);

#endif //FLAPPYBIRD_PHYSICS_ENGINE_H
