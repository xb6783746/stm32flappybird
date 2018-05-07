
#include <platform.h>
#include <flappybird.h>
#include <game_engine.h>
#include <internal/game_object_factory.h>
#include <internal/engine_event_handler.h>
#include <flappybird_settings.h>
#include <physics_engine.h>
#include <internal/object_buffer.h>
#include <internal/game_objects.h>


fb_game_settings_t flappybird_settings;
flappybird_bird_t flappybird_bird_t_arr[BIRDS_BUFFER_CAPACITY];

static fb_bool_t is_running;

static void init_field(void);

void fb_game_init(fb_game_settings_t *arg){

    is_running = FB_FALSE;

    flappybird_settings = *arg;

    gn_ph_settings_t engine_settings;

    engine_settings.screen_width = flappybird_settings.screen_width;
    engine_settings.screen_height = flappybird_settings.screen_height;
    engine_settings.on_collision = fb_on_collision;
    engine_settings.on_object_deleted = fb_on_object_deleted;
    engine_settings.bird_horizontal_velocity = BIRD_HORIZONTAL_VELOCITY;
    engine_settings.gravity = GRAVITY;

    gn_engine_init(&engine_settings);
}

void fb_game_start(){

    is_running = FB_TRUE;

    fb_object_buffer_init();

    gn_engine_reset();

    init_field();

    gn_engine_start();

    fb_go_factory_start();
}
void fb_game_stop(){

    is_running = FB_FALSE;

    gn_engine_stop();

    fb_go_factory_stop();
}

fb_bool_t fb_game_is_running(){

    return is_running;
}

static void init_field(){

    int i;
    for(i = 0; i < flappybird_settings.birds_count; i++){

        gn_game_object *bird = fb_object_buffer_get_game_object();

        flappybird_bird_t_arr[i].go = bird;
        flappybird_bird_t_arr[i].hp = BIRD_HP;

        bird->width = BIRD_WIDTH;
        bird->height = BIRD_HEIGHT;
        bird->vertical_velocity = 0;

        bird->point.x = BIRD_INITIAL_X + DIST_BETWEEN_BIRDS*i;
        bird->point.y = flappybird_settings.screen_height / 2;
        bird->is_static = FB_FALSE;

        gn_img_rectangle_t img;

        img.go = bird;
        img.color.green = 255;
        img.color.red = img.color.blue = 0;

        gn_phys_add_object(bird);
        gn_graphics_add_frect(&img);
    }
}

