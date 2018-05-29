

#include <physics_engine.h>
#include <internal/moving.h>
#include <internal/collision.h>

static void phys_init(void);
static void reset_field(void);

pe_settings_t settings;
pe_game_object *objects[PHYS_ENGINE_OBJECT_BUFFER_CAPACITY];

void phys_engine_init(pe_settings_t arg){

    settings = arg;

    phys_init();
}

void phys_engine_reset(void){

    phys_init();
}

void phys_engine_add_object(pe_game_object *obj){

    int i;
    for(i = 0; i < PHYS_ENGINE_OBJECT_BUFFER_CAPACITY; i++){

        if(objects[i] == FB_NULL){

            objects[i] = obj;
            break;
        }
    }
}

void phys_engine_set_gravity(fb_float32_t gravity){

    settings.gravity = gravity;
    phys_engine_set_gravity_internal(gravity);
}

void phys_engine_next(){

    phys_engine_move();
    phys_engine_process_collision();
}

static void reset_field(void){

    int i;
    for(i = 0; i < PHYS_ENGINE_OBJECT_BUFFER_CAPACITY; i++){

        objects[i] = FB_NULL;
    }
}

static void phys_init(void){

    reset_field();

    phys_engine_set_gravity_internal(settings.gravity);
}