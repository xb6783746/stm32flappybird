
#include <internal/collision.h>
#include <internal/game_field.h>


static void check_object_collisions(fb_uint8_t obj_num);
static fb_uint8_t check_collision(pe_game_object *obj1, pe_game_object *obj2);

void phys_engine_process_collision(){

    fb_uint8_t i;
    for(i = 0; i < PHYS_ENGINE_OBJECT_BUFFER_CAPACITY; i++){

        if(objects[i] != FB_NULL) {

            check_object_collisions(i);
        }
    }
}

static void check_object_collisions(fb_uint8_t obj_num){

    pe_game_object *obj = objects[obj_num];

    int i;
    for(i = obj_num + 1; i < PHYS_ENGINE_OBJECT_BUFFER_CAPACITY; i++){

        if(objects[i] != FB_NULL) {

            if(check_collision(obj, objects[i])){

                settings.on_collision(obj, objects[i]);
            }
        }
    }
}
static fb_uint8_t check_collision(pe_game_object *obj1, pe_game_object *obj2){


    pe_point_t bird_point = obj1->point;
    pe_point_t body_point = obj2->point;

    fb_float32_t bird_x_w = obj1->point.x + obj1->width;
    fb_float32_t bird_y_h = obj1->point.y + obj1->height;

    fb_float32_t body_x_w = obj2->point.x + obj2->width;
    fb_float32_t body_y_h = obj2->point.y + obj2->height;

    return (fb_uint8_t) !(bird_point.x > body_x_w || bird_point.y > body_y_h
                      || body_point.x > bird_x_w || body_point.y > bird_y_h);
}