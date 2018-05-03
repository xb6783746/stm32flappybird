

#ifndef FLAPPYBIRD_GAME_ENGINE_H
#define FLAPPYBIRD_GAME_ENGINE_H

#include <game_structs.h>

typedef void (*collision_callback)(gn_game_object *go1, gn_game_object *go2);
typedef void (*object_deleted_callback)(gn_game_object *go);

typedef struct gn_ph_settings_s {

    gn_velocity bird_horizontal_velocity;
    collision_callback on_collision;
    object_deleted_callback on_object_deleted;

    fb_uint16_t screen_width;
    fb_uint16_t screen_height;

    fb_float32_t gravity;
} gn_ph_settings_t;

void gn_engine_init(gn_ph_settings_t *settings);

void gn_engine_start(void);
void gn_engine_stop(void);
void gn_engine_restart(void);

#endif //FLAPPYBIRD_GAME_ENGINE_H
