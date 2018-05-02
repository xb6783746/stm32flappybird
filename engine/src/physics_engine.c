
#include <physics_engine.h>
#include <internal/moving.h>
#include <internal/collision.h>
#include <game_structs.h>
#include <timer_service.h>
#include <internal/game_field.h>
#include <game_engine.h>


void gn_physics_init(void){

    physics_engine_set_birds_horizontal_velocity(settings.bird_horizontal_velocity);
    physics_engine_set_gravity(settings.gravity);

    gn_phys_reset_field();
}

void physics_engine_add_bird(gn_bird_t *obj){

    gn_phys_add_bird_to_field(obj);
}

void physics_engine_set_birds_horizontal_velocity(gn_velocity vel){

    settings.bird_horizontal_velocity = vel;

    gn_phys_set_step(vel);
}

void physics_engine_add_bird_vertical_velocity(fb_uint8_t bird, gn_velocity vel){

    birds[bird].vertical_velocity = vel;
}

void physics_engine_set_gravity(uint16_t gravity){

    settings.gravity = gravity;

    gn_phys_set_gravity(gravity);
}

void physics_engine_add_solid_body(gn_solid_body_t *obj){

    gn_phys_add_body_to_field(obj);
}

void gn_physics_next(){

    gn_phys_move();
    gn_phys_process_collision();
}



