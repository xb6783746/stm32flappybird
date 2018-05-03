
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

static void init_field(void);

void fb_game_init(fb_game_settings_t *arg){

    flappybird_settings = *arg;

    gn_ph_settings_t engine_settings;

    engine_settings.screen_width = flappybird_settings.screen_width;
    engine_settings.screen_height = flappybird_settings.screen_height;
    engine_settings.on_collision = fb_on_collision;
    engine_settings.on_object_deleted = fb_on_object_deleted;
    engine_settings.bird_horizontal_velocity = BIRD_HORIZONTAL_VELOCITY;
    engine_settings.gravity = GRAVITY;

    fb_object_buffer_init();
    gn_engine_init(&engine_settings);

    init_field();
}

void fb_game_start(){

    gn_engine_start();

    fb_go_factory_start();
}
void fb_game_stop(){

    gn_engine_stop();

    fb_go_factory_stop();
}

static void init_field(){

    int i;
    for(i = 0; i < flappybird_settings.birds_count; i++){

        gn_game_object *go = fb_object_buffer_get_game_object();

        flappybird_bird_t_arr[i].go = go;
        flappybird_bird_t_arr[i].hp = BIRD_HP;

        gn_bird_t bird;

        bird.go = go;
        bird.width = BIRD_WIDTH;
        bird.height = BIRD_HEIGHT;
        bird.vertical_velocity = 0;

        go->point.x = BIRD_INITIAL_X + DIST_BETWEEN_BIRDS*i;
        go->point.y = flappybird_settings.screen_height / 2;

        gn_img_rectangle_t img;

        img.go = go;
        img.width = bird.width;
        img.height =  bird.height;
        img.color.green = 255;
        img.color.red = img.color.blue = 0;

        gn_phys_add_bird(&bird);
        gn_graphics_add_frect(&img);
    }
}

