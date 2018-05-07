
#include <physics_engine.h>
#include <internal/moving.h>
#include <internal/collision.h>
#include <internal/game_field.h>

gn_game_object *objects[OBJECTS_BUFFER_CAPACITY];


void gn_phys_init(void){

    gn_phys_set_gravity(settings.gravity);

    gn_phys_reset_field();
}


void gn_phys_set_gravity(fb_float32_t gravity){

    settings.gravity = gravity;

    gn_phys_set_gravity_internal(gravity);
}

void gn_phys_add_object(gn_game_object *obj){

    int i;
    for(i = 0; i < OBJECTS_BUFFER_CAPACITY; i++){

        if(objects[i] == NULL){

            objects[i] = obj;
            break;
        }
    }
}

void gn_phys_reset_field(void){

    int i;
    for(i = 0; i < OBJECTS_BUFFER_CAPACITY; i++){

        objects[i] = NULL;
    }
}

void gn_phys_next(){

    gn_phys_move();
    gn_phys_process_collision();
}



