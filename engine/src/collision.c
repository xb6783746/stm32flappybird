
#include <internal/collision.h>
#include <internal/game_field.h>


static void check_object_collisions(gn_game_object *bird, fb_uint8_t from);
static fb_uint8_t check_collision(gn_game_object *bird, gn_game_object *body);

void gn_phys_process_collision(){

    fb_uint8_t i;
    for(i = 0; i < OBJECTS_BUFFER_CAPACITY; i++){

        if(objects[i] != NULL) {

            check_object_collisions(objects[i], i);
        }
    }
}

static void check_object_collisions(gn_game_object *bird, fb_uint8_t from){

    int i;
    for(i = from + 1; i < OBJECTS_BUFFER_CAPACITY; i++){

        if(objects[i] != NULL) {

            if(check_collision(bird, objects[i])){

                settings.on_collision(bird, objects[i]);
            }
        }
    }
}
static fb_uint8_t check_collision(gn_game_object *bird, gn_game_object *body){


    gl_point_t bird_point = bird->point;
    gl_point_t body_point = body->point;

    fb_float32_t bird_x_w = bird->point.x + bird->width;
    fb_float32_t bird_y_h = bird->point.y + bird->height;

    fb_float32_t body_x_w = body->point.x + body->width;
    fb_float32_t body_y_h = body->point.y + body->height;

    return (fb_uint8_t) !(bird_point.x > body_x_w || bird_point.y > body_y_h
                      || body_point.x > bird_x_w || body_point.y > bird_y_h);
}