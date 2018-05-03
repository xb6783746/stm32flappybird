
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


void gn_phys_add_bird(gn_bird_t *obj);
void gn_phys_set_birds_horizontal_velocity(gn_velocity vel);
void gn_phys_set_bird_vertical_velocity(fb_uint8_t bird, gn_velocity vel);
void gn_phys_set_gravity(fb_float32_t gravity);
void gn_phys_add_solid_body(gn_solid_body_t *obj);

#endif //FLAPPYBIRD_PHYSICS_ENGINE_H
