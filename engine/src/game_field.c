
#include <internal/game_field.h>
#include <memory.h>

gn_game_object *objects[OBJECTS_BUFFER_CAPACITY];

void gn_phys_add_body_to_field(gn_game_object *obj){

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
