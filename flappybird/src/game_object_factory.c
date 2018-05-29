
#include <internal/game_object_factory.h>
#include <timer_service.h>
#include <internal/object_buffer.h>
#include <flappybird_settings.h>
#include <flappybird.h>
#include <random_service.h>
#include <physics_engine.h>

#define GO_FACTORY_PERIOD_TICKS (GO_FACTORY_CREATE_EVERY_S / TIMER_PERIOD_SEC)

extern fb_game_settings_t flappybird_settings;

static void create(void);
static void add_wall(fb_uint16_t hole_y_pos, fb_uint8_t is_upper);

void fb_go_factory_start(void){

    timer_service_call_periodically(create, (fb_uint32_t) GO_FACTORY_PERIOD_TICKS);
}

void fb_go_factory_stop(void){

    timer_service_delete(create);
}


static void create(void){

    fb_uint16_t from = WALL_HOLE_HEIGHT;
    fb_uint16_t to = (fb_uint16_t) (flappybird_settings.screen_height - 2 * WALL_HOLE_HEIGHT);

    fb_uint16_t hole_y_pos = (fb_uint16_t) fb_random_between(from, to);

    add_wall(hole_y_pos, FB_FALSE);
    add_wall(hole_y_pos, FB_TRUE);
}

static void add_wall(fb_uint16_t hole_y_pos, fb_uint8_t is_upper){

    flappybird_object_t *body = fb_object_buffer_get_object(Wall);


    body->go.width = WALL_WIDTH;
    body->go.height = is_upper?
                      hole_y_pos :
                      (fb_uint16_t) (flappybird_settings.screen_height - hole_y_pos - WALL_HOLE_HEIGHT);

    body->go.point.x = flappybird_settings.screen_width - WALL_WIDTH;
    body->go.point.y = is_upper? 0 : hole_y_pos + WALL_HOLE_HEIGHT;

    body->go.horizontal_velocity = BIRD_HORIZONTAL_VELOCITY;

    body->go.is_static = FB_TRUE;

    phys_engine_add_object(&body->go);

    gr_add_wall(&body->go);
}

