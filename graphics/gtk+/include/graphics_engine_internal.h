

#ifndef FLAPPYBIRD_GRAPHICS_ENGINE_H
#define FLAPPYBIRD_GRAPHICS_ENGINE_H

#include <geometric_primitives.h>
#include <game_structs.h>

#define IMG_BUFFER_CAPACITY 15

typedef struct gn_img_rectangle_s{

    gn_game_object *go;

    gl_color_t color;
} gn_img_rectangle_t;


void gn_graphics_add_frect(gn_img_rectangle_t *img);
void gn_graphics_delete(gn_game_object *go);

void gn_graphics_next(void);

#endif //FLAPPYBIRD_GRAPHICS_ENGINE_H
