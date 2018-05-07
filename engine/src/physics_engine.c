
#include <physics_engine.h>
#include <internal/moving.h>
#include <internal/collision.h>
#include <internal/game_field.h>


void gn_phys_init(void){

    gn_phys_set_gravity(settings.gravity);

    gn_phys_reset_field();
}


void gn_phys_set_gravity(fb_float32_t gravity){

    settings.gravity = gravity;

    gn_phys_set_gravity_internal(gravity);
}

void gn_phys_add_object(gn_game_object *obj){

    gn_phys_add_body_to_field(obj);
}

void gn_phys_next(){

    gn_phys_move();
    gn_phys_process_collision();
}



