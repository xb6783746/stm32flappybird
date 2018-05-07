

#ifndef FLAPPYBIRD_GAME_ENGINE_H
#define FLAPPYBIRD_GAME_ENGINE_H

#include <game_structs.h>

typedef void (*collision_callback)(gn_game_object *go1, gn_game_object *go2);
typedef void (*object_deleted_callback)(gn_game_object *go);

typedef struct gn_ph_settings_s {

    collision_callback on_collision;
    object_deleted_callback on_object_deleted;

    fb_uint16_t screen_width;
    fb_uint16_t screen_height;

    fb_float32_t gravity;

    fb_float32_t phys_cycle_s;
    fb_float32_t graphics_cycle_s;
} gn_ph_settings_t;

void gn_engine_init(gn_ph_settings_t *settings);

void gn_engine_reset(void);

#endif //FLAPPYBIRD_GAME_ENGINE_H
