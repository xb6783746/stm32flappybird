

#ifndef FLAPPYBIRD_GRAPHICS_ENGINE_H
#define FLAPPYBIRD_GRAPHICS_ENGINE_H

#include <geometric_primitives.h>
#include <game_structs.h>

#define IMG_BUFFER_CAPACITY 15
#define GRAPHICS_CYCLE_TICKS 30

#define GRAPHICS_TIME_STEP GRAPHICS_CYCLE_TICKS * TIMER_PERIOD_SEC

typedef struct gn_img_rectangle_s{

    gn_game_object *go;

    fb_uint16_t width;
    fb_uint16_t height;

    gl_color_t color;
} gn_img_rectangle_t;


void graphics_engine_add_frect(gn_img_rectangle_t *img);
void graphics_engine_delete(gn_game_object *go);

#endif //FLAPPYBIRD_GRAPHICS_ENGINE_H
