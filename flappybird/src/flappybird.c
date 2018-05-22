
#include <platform.h>
#include <flappybird.h>
#include <game_engine.h>
#include <internal/game_object_factory.h>
#include <internal/engine_event_handler.h>
#include <flappybird_settings.h>
#include <physics_engine.h>
#include <internal/object_buffer.h>


fb_game_settings_t flappybird_settings;

static fb_bool_t is_running;

static void init_field(void);

static void engine_start();
static void engine_stop();

static void on_next();

void fb_game_init(fb_game_settings_t *arg){

    is_running = FB_FALSE;

    flappybird_settings = *arg;

    gn_ph_settings_t engine_settings;

    engine_settings.screen_width = flappybird_settings.screen_width;
    engine_settings.screen_height = flappybird_settings.screen_height;
    engine_settings.on_collision = fb_on_collision;
    engine_settings.on_object_deleted = fb_on_object_deleted;
    engine_settings.gravity = GRAVITY;
    engine_settings.phys_cycle_s = PHYSICS_TIME_STEP;

    gn_engine_init(&engine_settings);
    gr_init();
}

void fb_game_start(){

    is_running = FB_TRUE;

    fb_object_buffer_init();

    gn_engine_reset();

    init_field();

    engine_start();

    fb_go_factory_start();
}
void fb_game_stop(){

    is_running = FB_FALSE;

    engine_stop();

    fb_go_factory_stop();
}

fb_bool_t fb_game_is_running(){

    return is_running;
}

static void init_field(){

    int i;
    for(i = 0; i < flappybird_settings.birds_count; i++){

        flappybird_object_t *bird = fb_object_buffer_get_object(Bird);

        bird->go.width = BIRD_WIDTH;
        bird->go.height = BIRD_HEIGHT;
        bird->go.vertical_velocity = 0;

        bird->go.point.x = BIRD_INITIAL_X + DIST_BETWEEN_BIRDS*i;
        bird->go.point.y = flappybird_settings.screen_height / 2;
        bird->go.is_static = FB_FALSE;

        gn_phys_add_object(&bird->go);
        gr_add_bird(&bird->go);
    }
}

static void engine_start(){

    timer_service_call_periodically(on_next, PHYSICS_CYCLE_TICKS);
}
static void engine_stop(){

    timer_service_delete(on_next);
}

static void on_next(){

    gn_phys_next();
    gr_update();
}

