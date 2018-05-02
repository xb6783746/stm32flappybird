

#include <internal/object_buffer.h>


typedef struct fb_bird_buffer_entry_s{

    fb_uint8_t is_free;
    gn_game_object go;

} fb_game_object_buffer_entry_t;


static fb_game_object_buffer_entry_t game_objects[GAME_OBJECT_BUFFER_CAPACITY];

void flappybird_object_buffer_init(void){

    int i;
    for(i = 0; i < GAME_OBJECT_BUFFER_CAPACITY; i++){

        game_objects[i].is_free = 1;
    }
}

void flappybird_object_buffer_release(gn_game_object *go){

    int i;
    for(i = 0; i < GAME_OBJECT_BUFFER_CAPACITY; i++){

        if(&game_objects[i].go == go) {

            game_objects[i].is_free = 1;
            break;
        }
    }
}

gn_game_object* flappybird_object_buffer_get_game_object(void){

    int i;
    for(i = 0; i < GAME_OBJECT_BUFFER_CAPACITY; i++){

        if(game_objects[i].is_free){

            game_objects[i].is_free = 0;

            return &game_objects[i].go;
        }
    }

    return 0;
}