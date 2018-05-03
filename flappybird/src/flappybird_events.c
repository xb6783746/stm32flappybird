

#include <flappybird_events.h>
#include <physics_engine.h>
#include <internal/game_objects.h>
#include <flappybird_settings.h>

extern flappybird_bird_t flappybird_bird_t_arr[BIRDS_BUFFER_CAPACITY];

void flappybird_tap(fb_uint8_t bird_num){

    gn_phys_set_bird_vertical_velocity(bird_num, BIRD_JUMP);
}