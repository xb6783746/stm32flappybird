
#define UNITY_INCLUDE_FLOAT

#include <unity.h>
#include <internal/collision.h>
#include <internal/game_field.h>

#define BIRD_SIZE 5
#define BODY_SIZE 10

gn_ph_settings_t settings;

#define BIRD_ID 0
#define BODY_ID 1

#define BIRD go[BIRD_ID]
#define BODY go[BODY_ID]

static gn_game_object go[2];

static fb_uint8_t on_deleted_called;

static void on_collision(gn_game_object *go1, gn_game_object *go2);
static void init_field(void);

void test_no_collision(){

    init_field();

    BIRD.point.x = 10;
    BIRD.point.y = 10;

    BODY.point.x = 50;
    BODY.point.y = 50;

    gn_phys_process_collision();

    TEST_ASSERT_EQUAL(on_deleted_called, 0);
}

void test_collision(void){

    init_field();

    BIRD.point.x = 10;
    BIRD.point.y = 10;

    BODY.point.x = 10.5f;
    BODY.point.y = 11;

    gn_phys_process_collision();

    TEST_ASSERT_EQUAL(on_deleted_called, 1);
}

static void on_collision(gn_game_object *go1, gn_game_object *go2){

    on_deleted_called = 1;

    TEST_ASSERT_EQUAL(&BIRD, go1);
    TEST_ASSERT_EQUAL(&BODY, go2);
}

static void init_field(){

    gn_phys_reset_field();

    on_deleted_called = 0;

    settings.on_collision = on_collision;

    BIRD.width = BIRD_SIZE;
    BIRD.height = BIRD_SIZE;

    BODY.width = BODY_SIZE;
    BODY.height = BODY_SIZE;

    gn_phys_add_bird_to_field(&BIRD);
    gn_phys_add_body_to_field(&BODY);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_no_collision);
    RUN_TEST(test_collision);
    return UNITY_END();
}