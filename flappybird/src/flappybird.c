
#include <platform.h>
#include <flappybird.h>
#include <physics_engine.h>
#include <internal/game_object_factory.h>
#include <internal/physics_engine_event_handler.h>
#include <flappybird_settings.h>
#include <internal/object_buffer.h>

#define PHYSICS_ENGINE_CYCLE_TICKS (PHYS_ENGINE_CYCLE_MS / TIMER_PERIOD_MSEC)

fb_game_settings_t flappybird_settings;

static fb_bool_t is_running;

static void init_field(void);

static void timer_start();
static void timer_end();

static void on_next();

void fb_game_init(fb_game_settings_t arg){

    is_running = FB_FALSE;

    flappybird_settings = arg;

    pe_settings_t engine_settings;

    engine_settings.screen_width = flappybird_settings.screen_width;
    engine_settings.screen_height = flappybird_settings.screen_height;
    engine_settings.on_collision = fb_on_collision;
    engine_settings.on_object_deleted = fb_on_object_deleted;
    engine_settings.gravity = GRAVITY;

    phys_engine_init(engine_settings);
    gr_init();
}

void fb_game_start(){

    is_running = FB_TRUE;

    fb_object_buffer_init();

    phys_engine_reset();

    gr_init();

    init_field();

    timer_start();

    fb_go_factory_start();
}
void fb_game_stop(){

    is_running = FB_FALSE;

    timer_end();

    fb_go_factory_stop();
}

fb_bool_t fb_game_is_running(){

    return is_running;
}

static void init_field(){

    fb_uint8_t i;
    for(i = 0; i < BIRD_COUNT; i++){

        flappybird_object_t *bird = fb_object_buffer_get_object(Bird);

        bird->bird.bird_number = i;

        bird->go.width = BIRD_WIDTH;
        bird->go.height = BIRD_HEIGHT;
        bird->go.vertical_velocity = 0;

        bird->go.point.x = BIRD_INITIAL_X + DIST_BETWEEN_BIRDS*i;
        bird->go.point.y = flappybird_settings.screen_height / 2;
        bird->go.is_static = FB_FALSE;

        phys_engine_add_object(&bird->go);
        gr_add_bird(&bird->go);
    }
}

static void timer_start(){

    timer_service_call_periodically(on_next, PHYSICS_ENGINE_CYCLE_TICKS);
}
static void timer_end(){

    timer_service_delete(on_next);
}

static void on_next(){

    phys_engine_next();
    gr_update();
}

