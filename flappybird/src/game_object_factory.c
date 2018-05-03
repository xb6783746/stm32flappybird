
#include <internal/game_object_factory.h>
#include <timer_service.h>
#include <internal/object_buffer.h>
#include <flappybird_settings.h>
#include <flappybird.h>
#include <random_service.h>

#define PERIOD_TICKS (CREATE_EVERY_S / TIMER_PERIOD_SEC)

extern fb_game_settings_t flappybird_settings;

static void create(void);

static void add_pipe(fb_uint16_t hole_height, fb_uint8_t is_upper);
static void add_image(gn_solid_body_t *body, gl_color_t color);

void fb_go_factory_start(void){

    timer_service_call_periodically(create, (fb_uint32_t) PERIOD_TICKS);
}

void fb_go_factory_stop(void){

    timer_service_delete(create);
}


static void create(void){

    fb_uint16_t from = PIPE_HOLE_SIZE;
    fb_uint16_t to = (fb_uint16_t) (flappybird_settings.screen_height - 2 * PIPE_HOLE_SIZE);

    fb_uint16_t hole_height = (fb_uint16_t) fb_random_between(from, to); //(fb_uint16_t) fb_random();

    add_pipe(hole_height, 0);
    add_pipe(hole_height, 1);
}

static void add_pipe(fb_uint16_t hole_height, fb_uint8_t is_upper){

    gn_game_object *go = fb_object_buffer_get_game_object();

    gn_solid_body_t body;

    body.go = go;
    body.width = PIPE_WIDTH;
    body.height = is_upper?
                      hole_height : (fb_uint16_t) (flappybird_settings.screen_height - hole_height - PIPE_HOLE_SIZE);

    go->point.x = flappybird_settings.screen_width - PIPE_WIDTH;
    go->point.y = is_upper? 0 : hole_height + PIPE_HOLE_SIZE;

    gn_phys_add_solid_body(&body);

    gl_color_t color;
    color.red = color.green = color.blue = 0;

    add_image(&body, color);
}

static void add_image(gn_solid_body_t *body, gl_color_t color){


    gn_img_rectangle_t rect;

    rect.go = body->go;
    rect.width = body->width;
    rect.height = body->height;
    rect.color = color;

    gn_graphics_add_frect(&rect);
}


