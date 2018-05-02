

#ifndef FLAPPYBIRD_FLAPPYBIRD_H
#define FLAPPYBIRD_FLAPPYBIRD_H

#include <plathorm.h>

typedef void (*on_game_over_callback)(fb_uint8_t bird_num);

typedef struct fb_game_settings_s {

    fb_uint8_t birds_count;
    on_game_over_callback on_game_over;

    fb_uint16_t screen_width;
    fb_uint16_t screen_height;
} fb_game_settings_t;

void flappybird_init(fb_game_settings_t *settings);

void flappybird_start();
void flappybird_stop();


#endif //FLAPPYBIRD_FLAPPYBIRD_H
