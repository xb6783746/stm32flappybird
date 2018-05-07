

#include <flappybird_events.h>
#include <physics_engine.h>
#include <internal/game_objects.h>
#include <flappybird_settings.h>

extern flappybird_bird_t flappybird_bird_t_arr[BIRDS_BUFFER_CAPACITY];

void fb_bird_jump(fb_uint8_t bird_num){

    flappybird_bird_t_arr[bird_num].go->vertical_velocity = BIRD_JUMP;
}