
#include <internal/moving.h>
#include <internal/game_field.h>


fb_float32_t gravity;

static void process_gravity(gn_game_object *go);


void gn_phys_set_gravity_internal(fb_float32_t arg){

    gravity = arg * PHYSICS_TIME_STEP;
}

void gn_phys_move(void){

    int i;
    for(i = 0; i < OBJECTS_BUFFER_CAPACITY; i++){

        if(objects[i] != NULL){

            objects[i]->point.x += objects[i]->horizontal_velocity * PHYSICS_TIME_STEP;

            if(objects[i]->point.x + objects[i]->width < 0){

                settings.on_object_deleted(objects[i]);

                objects[i] = NULL;
                continue;
            }

            if(!objects[i]->is_static){

                process_gravity(objects[i]);
            }
        }
    }
}

static void process_gravity(gn_game_object *go){

    go->vertical_velocity += gravity;
    go->point.y += go->vertical_velocity * PHYSICS_TIME_STEP;

    if(go->point.y + go->height >= settings.screen_height){

        go->point.y = settings.screen_height - go->height;
        go->vertical_velocity = 0;
    } else if(go->point.y <= 0){

        go->point.y = 0;
        go->vertical_velocity = 0;
    }
}