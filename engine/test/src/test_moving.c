
#define UNITY_INCLUDE_FLOAT

#include <unity.h>
#include <internal/moving.h>
#include <internal/game_field.h>
#include <memory.h>
#include <game_structs.h>


#define SCREEN_HEIGHT 100
#define SCREEN_WIDTH 100

#define BIRD_SIZE 5
#define BODY_SIZE 10

#define VERTICAL_VELOCITY 20
#define HORIZONTAL_VELOCITY -20
#define GRAVITY 5

#define VERT_VEL_DELTA GRAVITY * PHYSICS_TIME_STEP
#define Y_POS_DELTA(v) ((v) * PHYSICS_TIME_STEP)
#define X_POS_DELTA HORIZONTAL_VELOCITY * PHYSICS_TIME_STEP

gn_ph_settings_t settings;

static gn_game_object go[2];

static gn_bird_t bird;
static gn_solid_body_t body;

static fb_uint8_t on_deleted_called;

static void on_deleted(gn_game_object *go);
static void init_field(void);

void test_move_body(){

    init_field();

    bird.go->point.x = 10;
    bird.go->point.y = 10;

    body.go->point.x = 50;
    body.go->point.y = 50;

    gn_phys_move();

    TEST_ASSERT_EQUAL_FLOAT(body.go->point.x - 50, X_POS_DELTA);
    TEST_ASSERT_EQUAL_FLOAT(body.go->point.y - 50, 0);

    TEST_ASSERT_EQUAL_FLOAT(birds[0].vertical_velocity - VERTICAL_VELOCITY, VERT_VEL_DELTA);
    TEST_ASSERT_EQUAL_FLOAT(bird.go->point.x - 10, 0);
    TEST_ASSERT_EQUAL_FLOAT(bird.go->point.y - 10, Y_POS_DELTA(birds[0].vertical_velocity));

    TEST_ASSERT_EQUAL(on_deleted_called, 0);
}

void test_delete_objects(void){

    init_field();

    bird.go->point.x = 10;
    bird.go->point.y = 10;

    body.go->point.x = -9.5f;
    body.go->point.y = 50;

    gn_phys_move();

    TEST_ASSERT_EQUAL(on_deleted_called, 1);
}

static void on_deleted(gn_game_object *go){

    on_deleted_called = 1;

    TEST_ASSERT_EQUAL(body.go, go);
}

static void init_field(){

    gn_phys_reset_field();

    on_deleted_called = 0;

    settings.screen_height = SCREEN_HEIGHT;
    settings.screen_width = SCREEN_WIDTH;

    settings.on_object_deleted = on_deleted;

    settings.gravity = 5;
    settings.bird_horizontal_velocity = HORIZONTAL_VELOCITY;

    bird.go = &go[0];
    bird.width = BIRD_SIZE;
    bird.width = BIRD_SIZE;
    bird.vertical_velocity = VERTICAL_VELOCITY;

    body.go = &go[1];
    body.width = BODY_SIZE;
    body.height = BODY_SIZE;

    gn_phys_add_bird_to_field(&bird);
    gn_phys_add_body_to_field(&body);

    gn_phys_set_step(HORIZONTAL_VELOCITY);
    gn_phys_set_gravity(GRAVITY);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_move_body);
    RUN_TEST(test_delete_objects);
    return UNITY_END();
}