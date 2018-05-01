
#include <physics_engine.h>
#include <internal/moving.h>
#include <internal/collision.h>
#include <game_structs.h>
#include <timer_service.h>
#include <internal/game_field.h>

gn_ph_settings_t settings;

gn_solid_body_t *bodies[SOLID_BODIES_BUFFER_CAPACITY];
gn_bird_t *birds[BIRDS_BUFFER_CAPACITY];

static void on_next(void);

void physics_engine_init(gn_ph_settings_t *arg){

    settings = *arg;

    physics_engine_set_birds_horizontal_velocity(settings.bird_horizontal_velocity);
    physics_engine_set_gravity(settings.gravity);

    gn_phys_reset_field();

    timer_service_call_periodically(on_next, PHYSICS_CYCLE_TICKS);
}

void physics_engine_add_bird(gn_bird_t *obj){

    gn_phys_add_bird_to_field(obj);
}

void physics_engine_set_birds_horizontal_velocity(gn_velocity vel){

    settings.bird_horizontal_velocity = vel;

    gn_phys_set_step(vel);
}

void physics_engine_set_gravity(uint16_t gravity){

    settings.gravity = gravity;

    gn_phys_set_gravity(gravity);
}

void physics_engine_add_solid_body(gn_solid_body_t *obj){

    gn_phys_add_body_to_field(obj);
}

static void on_next(){

    gn_phys_move();
    gn_phys_process_collision();
}



