

#include <physics_engine.h>
#include <internal/game_objects.h>
#include <flappybird.h>
#include <internal/object_buffer.h>

extern fb_game_settings_t flappybird_settings;
extern flappybird_bird_t flappybird_bird_t_arr[BIRDS_BUFFER_CAPACITY];

void fb_on_object_deleted(gn_game_object *go){

    fb_object_buffer_release(go);
}

void fb_on_collision(gn_game_object *go1, gn_game_object *go2){

    int i;
    for(i = 0; i < BIRDS_BUFFER_CAPACITY; i++){

        if(flappybird_bird_t_arr[i].go == go1){

            flappybird_bird_t_arr[i].hp--;

            if(flappybird_bird_t_arr[i].hp <= 0){

                flappybird_settings.on_game_over(i);
                break;
            }
        }
    }

}