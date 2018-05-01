

#ifndef FLAPPYBIRD_GRAPHICS_H
#define FLAPPYBIRD_GRAPHICS_H

#include <geometric_primitives.h>

void graphics_clear(gl_color_t color);

void graphics_draw_rect(gl_rectangle_t *obj);
void graphics_draw_frect(gl_filled_rectangle_t *obj);
void graphics_draw_circle(gl_circle_t *obj);
void graphics_draw_fcircle(gl_filled_circle_t *obj);

#endif //FLAPPYBIRD_GRAPHICS_H
