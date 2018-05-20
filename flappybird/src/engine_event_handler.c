

#include <physics_engine.h>
#include <internal/game_objects.h>
#include <flappybird.h>
#include <internal/object_buffer.h>

extern fb_game_settings_t flappybird_settings;

static void process_collision(flappybird_object_t *go1, flappybird_object_t *go2);

static void process_collision_with_wall(flappybird_object_t *bird, flappybird_object_t *obj);
static void process_collision_with_bonus(flappybird_object_t *bird, flappybird_object_t *obj);

void fb_on_object_deleted(gn_game_object *go){

    fb_object_buffer_release(go);
    gr_delete(go);
}

void fb_on_collision(gn_game_object *go1, gn_game_object *go2){

    int i;

    flappybird_object_t *obj1 = FB_NULL;
    flappybird_object_t *obj2 = FB_NULL;

    for(i = 0; i < GAME_OBJECT_BUFFER_CAPACITY; i++){

        gn_game_object *go = &game_objects[i].obj.go;

        if(go == go1){

            obj1 = &game_objects[i].obj;
        }

        if(go == go2){

            obj2 = &game_objects[i].obj;
        }
    }

    if(obj1 != FB_NULL && obj2 != FB_NULL) {

        process_collision(obj1, obj2);
    }
}

static void process_collision(flappybird_object_t *go1, flappybird_object_t *go2){

    flappybird_object_t *bird = go1->type == Bird ? go1 : go2;
    flappybird_object_t *obj = bird == go1? go2 : go1;

    switch (obj->type){

        case Bonus:
            process_collision_with_bonus(bird, obj);
            break;
        case Bird:
            break;
        case Wall:
            process_collision_with_wall(bird, obj);
            break;
    }
}

static void process_collision_with_wall(flappybird_object_t *bird, flappybird_object_t *obj){


    bird->bird.hp--;

    if(bird->bird.hp <= 0){

        flappybird_settings.on_game_over(bird->bird.bird_number);
    }
}
static void process_collision_with_bonus(flappybird_object_t *bird, flappybird_object_t *obj){


}