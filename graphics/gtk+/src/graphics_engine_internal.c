
#include <graphics_engine_internal.h>
#include <graphics.h>

static gl_color_t white;

static gn_img_rectangle_t image_arr[IMG_BUFFER_CAPACITY];

static void draw_image(gn_img_rectangle_t *img);

void gr_init(void){

    white.red = 255;
    white.green = 255;
    white.blue = 255;

    int i;
    for(i = 0; i < IMG_BUFFER_CAPACITY; i++){

        image_arr[i].go = FB_NULL;
    }
}

void gr_update(void){

    graphics_clear(white);

    int i;
    for(i = 0; i < IMG_BUFFER_CAPACITY; i++){

        if(image_arr[i].go != FB_NULL){

            draw_image(&image_arr[i]);
        }
    }
}

void gn_graphics_add_frect(gn_img_rectangle_t *img){

    int i;
    for(i = 0; i < IMG_BUFFER_CAPACITY; i++){

        if(image_arr[i].go == FB_NULL){

            image_arr[i] = *img;
            break;
        }
    }
}

void gn_graphics_delete(pe_game_object *go){

    int i;
    for(i = 0; i < IMG_BUFFER_CAPACITY; i++){

        if(image_arr[i].go != FB_NULL && image_arr[i].go == go){

            image_arr[i].go = FB_NULL;
        }
    }
}


static void draw_image(gn_img_rectangle_t *img){


    gl_filled_rectangle_t frect;


    frect.point.x = img->go->point.x;
    frect.point.y = img->go->point.y;
    frect.color = img->color;
    frect.width = img->go->width;
    frect.height = img->go->height;

    graphics_draw_frect(&frect);

}
