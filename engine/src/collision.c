
#include <internal/collision.h>
#include <internal/game_field.h>
#include <game_structs.h>


static fb_uint8_t check_bird_collision(gn_bird_t *bird);
static fb_uint8_t check_collision(gn_bird_t *bird, gn_solid_body_t *body);

void gn_phys_process_collision(){

    int i;
    for(i = 0; i < BIRDS_BUFFER_CAPACITY; i++){

        if(birds[i].go != NULL) {

            check_bird_collision(&birds[i]);
        }
    }
}

static fb_uint8_t check_bird_collision(gn_bird_t *bird){

    int i;
    for(i = 0; i < SOLID_BODIES_BUFFER_CAPACITY; i++){

        if(bodies[i].go != NULL) {

            if(check_collision(bird, &bodies[i])){

                settings.on_collision(bird->go, bodies[i].go);
            }
        }
    }
}
static fb_uint8_t check_collision(gn_bird_t *bird, gn_solid_body_t *body){


    gl_point_t bird_point = bird->go->point;
    gl_point_t body_point = body->go->point;

    fb_float32_t bird_x_w = bird->go->point.x + bird->width;
    fb_float32_t bird_y_h = bird->go->point.y + bird->height;

    fb_float32_t body_x_w = body->go->point.x + body->width;
    fb_float32_t body_y_h = body->go->point.y + body->height;

    return (fb_uint8_t) !(bird_point.x > body_x_w || bird_point.y > body_y_h
                      || body_point.x > bird_x_w || body_point.y > bird_y_h);
}