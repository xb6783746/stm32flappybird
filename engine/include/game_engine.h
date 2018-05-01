

#ifndef FLAPPYBIRD_GAME_ENGINE_H
#define FLAPPYBIRD_GAME_ENGINE_H

typedef void (*collision_callback)(gn_game_object *go1, gn_game_object *go2);
typedef void (*object_deleted_callback)(gn_game_object *go);

typedef struct gn_ph_settings_s {

    gn_velocity bird_horizontal_velocity;
    collision_callback on_collision;
    object_deleted_callback on_object_deleted;

    fb_uint16_t screen_width;
    fb_uint16_t screen_height;

    fb_uint16_t gravity;
} gn_ph_settings_t;

void game_engine_init(gn_ph_settings_t *settings);

void game_engine_start(void);
void game_engine_stop(void);
void game_engine_restart(void);

#endif //FLAPPYBIRD_GAME_ENGINE_H
