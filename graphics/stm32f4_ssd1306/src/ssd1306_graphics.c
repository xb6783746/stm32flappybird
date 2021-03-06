
#include <graphics_engine.h>
#include <ssd1306_driver.h>

#define IMG_BUFFER_COUNT 15


static pe_game_object* buffer[IMG_BUFFER_COUNT];

static void reset_buffer(void);
static void add_to_buffer(pe_game_object *go);
static void draw_rect(pe_game_object *go);

void gr_init(void){

    ssd1306_driver_init();
    reset_buffer();
}

void gr_update(void){

    ssd1306_driver_fill(Ssd1306_Black);

    int i;
    for(i = 0; i < IMG_BUFFER_COUNT; i++){

        if(buffer[i] != FB_NULL){

            draw_rect(buffer[i]);
        }
    }

    ssd1306_driver_update();
}

void gr_add_bird(pe_game_object *go){

    add_to_buffer(go);
}
void gr_add_wall(pe_game_object *go){

    add_to_buffer(go);
}

void gr_delete(pe_game_object *go){

    int i;
    for(i = 0; i < IMG_BUFFER_COUNT; i++){

        if(buffer[i] == go){

            buffer[i] = FB_NULL;
        }
    }
}

static void add_to_buffer(pe_game_object *go){

    int i;
    for(i = 0; i < IMG_BUFFER_COUNT; i++){

        if(buffer[i] == FB_NULL){

            buffer[i] = go;
            break;
        }
    }
}

static void reset_buffer(void){

    int i;
    for(i = 0; i < IMG_BUFFER_COUNT; i++){

        buffer[i] = FB_NULL;
    }
}

static void draw_rect(pe_game_object *go){

    ssd1306_driver_fill_region(
            (int16_t) go->point.x, (int16_t) go->point.y,
            go->width, go->height,
            Ssd1306_White
    );
}