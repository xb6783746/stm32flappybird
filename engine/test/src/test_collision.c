
#define UNITY_INCLUDE_FLOAT

#include <unity.h>
#include <internal/collision.h>
#include <physics_engine.h>
#include <game_structs.h>

#define BIRD_SIZE 5
#define BODY_SIZE 10

pe_settings_t settings;

#define BIRD_ID 0
#define WALL_ID 1

#define BIRD objects[BIRD_ID]
#define WALL objects[WALL_ID]

pe_game_object *objects[PHYS_ENGINE_OBJECT_BUFFER_CAPACITY];

static pe_game_object bird, wall;
static fb_uint8_t on_deleted_called;


static void on_collision(pe_game_object *go1, pe_game_object *go2);
static void init_field(void);

void test_no_collision(){

    init_field();

    BIRD->point.x = 10;
    BIRD->point.y = 10;

    WALL->point.x = 50;
    WALL->point.y = 50;

    phys_engine_process_collision();

    TEST_ASSERT_EQUAL(on_deleted_called, 0);
}

void test_collision(void){

    init_field();

    BIRD->point.x = 10;
    BIRD->point.y = 10;

    WALL->point.x = 10.5f;
    WALL->point.y = 11;

    phys_engine_process_collision();

    TEST_ASSERT_EQUAL(on_deleted_called, 1);
}

static void on_collision(pe_game_object *go1, pe_game_object *go2){

    on_deleted_called = 1;
}

static void init_field(){
    
    int i;
    for(i = 0; i < PHYS_ENGINE_OBJECT_BUFFER_CAPACITY; i++){

        objects[i] = FB_NULL;
    }

    on_deleted_called = 0;
    BIRD = &bird;
    WALL = &wall;

    settings.on_collision = on_collision;

    BIRD->width = BIRD_SIZE;
    BIRD->height = BIRD_SIZE;

    WALL->width = BODY_SIZE;
    WALL->height = BODY_SIZE;
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_no_collision);
    RUN_TEST(test_collision);
    return UNITY_END();
}