

#include <internal/object_buffer.h>


fb_buffer_entry_t game_objects[GAME_OBJECT_BUFFER_CAPACITY];

void fb_object_buffer_init(void){

    int i;
    for(i = 0; i < GAME_OBJECT_BUFFER_CAPACITY; i++){

        game_objects[i].is_free = 1;
    }
}

void fb_object_buffer_release(gn_game_object *go){

    int i;
    for(i = 0; i < GAME_OBJECT_BUFFER_CAPACITY; i++){

        if(&game_objects[i].obj.go == go) {

            game_objects[i].is_free = 1;
            break;
        }
    }
}

flappybird_object_t* fb_object_buffer_get_object(flappybird_object_type_t type){

    int i;
    for(i = 0; i < GAME_OBJECT_BUFFER_CAPACITY; i++){

        if(game_objects[i].is_free){

            game_objects[i].is_free = 0;

            game_objects[i].obj.type = type;

            return &game_objects[i].obj;
        }
    }

    return FB_NULL;
}