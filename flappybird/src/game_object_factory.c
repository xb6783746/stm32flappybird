
#include <internal/game_object_factory.h>
#include <timer_service.h>
#include <internal/object_buffer.h>
#include <flappybird_settings.h>
#include <flappybird.h>
#include <game_structs.h>

#define PERIOD_TICKS (CREATE_EVERY_S / TIMER_PERIOD_SEC)

extern fb_game_settings_t flappybird_settings;

static void create(void);

void flappybird_go_factory_start(void){

    timer_service_call_periodically(create, (fb_uint32_t) PERIOD_TICKS);
}

void flappybird_go_factory_stop(void){

    timer_service_delete(create);
}

//TODO randomize pipes
static void create(void){

    gn_game_object *go = flappybird_object_buffer_get_game_object();

    gn_solid_body_t body;

    body.go = go;
    body.width = PIPE_HOLE_SIZE;
    body.height = (fb_uint16_t) (flappybird_settings.screen_height / 3);

    go->point.x = flappybird_settings.screen_width - PIPE_HOLE_SIZE;
    go->point.y = flappybird_settings.screen_height - body.height;

    physics_engine_add_solid_body(&body);

    gn_img_rectangle_t rect;

    rect.go = go;
    rect.width = body.width;
    rect.height = body.height;
    rect.color.red = rect.color.green = rect.color.blue = 0;

    graphics_engine_add_frect(&rect);
}


