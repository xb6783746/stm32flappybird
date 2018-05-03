
#include <graphics_engine.h>
#include <internal/graphics_internal.h>
#include <unity.h>
#include <Mockgraphics.h>


#define IMG_COUNT 3

static gl_color_t white = {255,255,255};

static gn_game_object objs[IMG_COUNT];
static gn_img_rectangle_t imgs[IMG_COUNT];

static gl_filled_rectangle_t expectedRects[IMG_COUNT];

static void init(void);
static void build_frect(gl_filled_rectangle_t *frect, gn_img_rectangle_t *img);

void test_redraw(void){

    init();

    gn_graphics_init();

    gn_graphics_add_frect(&imgs[0]);
    gn_graphics_add_frect(&imgs[1]);

    graphics_clear_Expect(white);

    graphics_draw_frect_Expect(&expectedRects[0]);
    graphics_draw_frect_Expect(&expectedRects[1]);

    gn_graphics_next();
}

void test_delete(void){

    init();

    gn_graphics_init();

    gn_graphics_add_frect(&imgs[0]);
    gn_graphics_add_frect(&imgs[1]);
    gn_graphics_add_frect(&imgs[2]);

    gn_graphics_delete(imgs[1].go);

    graphics_clear_Expect(white);

    graphics_draw_frect_Expect(&expectedRects[0]);
    graphics_draw_frect_Expect(&expectedRects[2]);

    gn_graphics_next();
}

static void init(void){

    int i;
    for(i = 0; i < IMG_COUNT; i++){

        imgs[i].go = &objs[i];

        build_frect(&expectedRects[i], &imgs[i]);
    }
}

static void build_frect(gl_filled_rectangle_t *frect, gn_img_rectangle_t *img){

    frect->width = img->width;
    frect->height = img->height;
    frect->color = img->color;
    frect->point = img->go->point;
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_redraw);
    RUN_TEST(test_delete);
    return UNITY_END();
}