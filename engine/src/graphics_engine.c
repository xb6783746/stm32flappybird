
#include <graphics_engine.h>
#include <graphics.h>
#include <game_structs.h>

static gl_color_t white;

static gn_img_rectangle_t image_arr[IMG_BUFFER_CAPACITY];

static void draw_image(gn_img_rectangle_t *img);

void gn_graphics_init(void){

    white.red = 255;
    white.green = 255;
    white.blue = 255;

    int i;
    for(i = 0; i < IMG_BUFFER_CAPACITY; i++){

        image_arr[i].go = NULL;
    }
}

void gn_graphics_next(void){

    graphics_clear(white);

    int i;
    for(i = 0; i < IMG_BUFFER_CAPACITY; i++){

        if(image_arr[i].go != NULL){

            draw_image(&image_arr[i]);
        }
    }
}

void graphics_engine_add_frect(gn_img_rectangle_t *img){

    int i;
    for(i = 0; i < IMG_BUFFER_CAPACITY; i++){

        if(image_arr[i].go == NULL){

            image_arr[i] = *img;
            break;
        }
    }
}

void graphics_engine_delete(gn_game_object *go){

    int i;
    for(i = 0; i < IMG_BUFFER_CAPACITY; i++){

        if(image_arr[i].go != NULL && image_arr[i].go == go){

            image_arr[i].go = NULL;
        }
    }
}


static void draw_image(gn_img_rectangle_t *img){


    gl_filled_rectangle_t frect;

    frect.point = img->go->point;
    frect.color = img->color;
    frect.width = img->width;
    frect.height = img->height;

    graphics_draw_frect(&frect);

}
