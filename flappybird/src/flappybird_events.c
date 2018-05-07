

#include <flappybird_events.h>
#include <physics_engine.h>
#include <internal/game_objects.h>
#include <flappybird_settings.h>
#include <internal/object_buffer.h>

extern flappybird_bird_t flappybird_bird_t_arr[BIRDS_BUFFER_CAPACITY];

void fb_bird_jump(fb_uint8_t bird_num){

    int i;
    for(i = 0; i < GAME_OBJECT_BUFFER_CAPACITY; i++){

        if(game_objects[i].obj.type == Bird && game_objects[i].obj.bird.bird_number == bird_num){

            game_objects[i].obj.go.vertical_velocity = BIRD_JUMP;
        }
    }
}