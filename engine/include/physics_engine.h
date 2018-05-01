
#ifndef FLAPPYBIRD_PHYSICS_ENGINE_H
#define FLAPPYBIRD_PHYSICS_ENGINE_H

#include <game_structs.h>
#include <timer_service.h>

#define SOLID_BODIES_BUFFER_CAPACITY 10
#define BIRDS_BUFFER_CAPACITY 3
#define PHYSICS_CYCLE_TICKS 30

#define PHYSICS_TIME_STEP PHYSICS_CYCLE_TICKS * TIMER_PERIOD_SEC

typedef struct gn_solid_body_s {

    gn_game_object *go;
    fb_uint16_t width;
    fb_uint16_t height;
} gn_solid_body_t;

typedef struct gn_bird_s {

    gn_game_object *go;

    fb_uint16_t width;
    fb_uint16_t height;

    gn_velocity vertical_velocity;
} gn_bird_t;


void physics_engine_add_bird(gn_bird_t *obj);
void physics_engine_set_birds_horizontal_velocity(gn_velocity vel);
void physics_engine_set_gravity(fb_uint16_t gravity);
void physics_engine_add_solid_body(gn_solid_body_t *obj);

#endif //FLAPPYBIRD_PHYSICS_ENGINE_H
