

#ifndef FLAPPYBIRD_FLAPPYBIRD_H
#define FLAPPYBIRD_FLAPPYBIRD_H


typedef void (*on_game_over_callback)(fb_uint8_t bird_num);

typedef struct fb_game_settings_s {

    on_game_over_callback on_game_over;

    fb_uint16_t screen_width;
    fb_uint16_t screen_height;
} fb_game_settings_t;

void fb_game_init(fb_game_settings_t settings);

void fb_game_start();
void fb_game_stop();

fb_bool_t fb_game_is_running(void);


#endif //FLAPPYBIRD_FLAPPYBIRD_H
