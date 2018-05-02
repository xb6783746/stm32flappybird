
#include <internal/moving.h>
#include <internal/game_field.h>
#include <game_structs.h>


fb_float32_t step;
fb_float32_t gravity;

static void move_bodies(void);
static void move_birds(void);

void gn_phys_set_step(fb_float32_t arg){

    step = arg * PHYSICS_TIME_STEP;
}

void gn_phys_set_gravity(fb_float32_t arg){

    gravity = arg * PHYSICS_TIME_STEP;
}

void gn_phys_move(void){

    move_bodies();
    move_birds();
}

static void move_bodies(void){

    int i;
    for(i = 0; i < SOLID_BODIES_BUFFER_CAPACITY; i++){

        if(bodies[i].go != NULL){

            bodies[i].go->point.x += step;

            if(bodies[i].go->point.x + bodies[i].width < 0){

                settings.on_object_deleted(bodies[i].go);

                bodies[i].go = NULL;
            }
        }
    }
}
static void move_birds(void){

    int i;
    for(i = 0; i < BIRDS_BUFFER_CAPACITY; i++){

        if(birds[i].go != NULL){

            birds[i].vertical_velocity += gravity;
            birds[i].go->point.y += birds[i].vertical_velocity * PHYSICS_TIME_STEP;

            if(birds[i].go->point.y + birds[i].height >= settings.screen_height){

                birds[i].go->point.y = settings.screen_height - birds[i].height;
                birds[i].vertical_velocity = 0;
            } else if(birds[i].go->point.y <= 0){

                birds[i].go->point.y = 0;
                birds[i].vertical_velocity = 0;
            }
        }
    }
}