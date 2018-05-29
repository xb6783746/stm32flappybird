
#include <internal/moving.h>
#include <internal/game_field.h>


#define PHYS_CYCLE_S ((PHYS_ENGINE_CYCLE_MS) / 1000.0f)

fb_float32_t velocity_step;

static void process_gravity(pe_game_object *go);

void phys_engine_set_gravity_internal(fb_float32_t arg){

    velocity_step = arg * PHYS_CYCLE_S;
}

void phys_engine_move(void){

    int i;
    for(i = 0; i < PHYS_ENGINE_OBJECT_BUFFER_CAPACITY; i++){

        if(objects[i] != FB_NULL){

            objects[i]->point.x += objects[i]->horizontal_velocity * PHYS_CYCLE_S;

            if(objects[i]->point.x + objects[i]->width < 0){

                settings.on_object_deleted(objects[i]);

                objects[i] = FB_NULL;
                continue;
            }

            if(!objects[i]->is_static){

                process_gravity(objects[i]);
            }
        }
    }
}

static void process_gravity(pe_game_object *go){

    go->vertical_velocity += velocity_step;
    go->point.y += go->vertical_velocity * PHYS_CYCLE_S;

    if(go->point.y + go->height >= settings.screen_height){

        go->point.y = settings.screen_height - go->height;
        go->vertical_velocity = 0;
    } else if(go->point.y <= 0){

        go->point.y = 0;
        go->vertical_velocity = 0;
    }
}