
#define UNITY_INCLUDE_FLOAT

#include <unity.h>
#include <internal/collision.h>
#include <internal/game_field.h>

#define BIRD_SIZE 5
#define BODY_SIZE 10

gn_ph_settings_t settings;

static gn_game_object go[2];

static gn_bird_t bird;
static gn_solid_body_t body;

static fb_uint8_t on_deleted_called;

static void on_collision(gn_game_object *go1, gn_game_object *go2);
static void init_field(void);

void test_no_collision(){

    init_field();

    bird.go->point.x = 10;
    bird.go->point.y = 10;

    body.go->point.x = 50;
    body.go->point.y = 50;

    gn_phys_process_collision();

    TEST_ASSERT_EQUAL(on_deleted_called, 0);
}

void test_collision(void){

    init_field();

    bird.go->point.x = 10;
    bird.go->point.y = 10;

    body.go->point.x = 10.5f;
    body.go->point.y = 11;

    gn_phys_process_collision();

    TEST_ASSERT_EQUAL(on_deleted_called, 1);
}

static void on_collision(gn_game_object *go1, gn_game_object *go2){

    on_deleted_called = 1;

    TEST_ASSERT_EQUAL(bird.go, go1);
    TEST_ASSERT_EQUAL(body.go, go2);
}

static void init_field(){

    gn_phys_reset_field();

    on_deleted_called = 0;

    settings.on_collision = fb_on_collision;

    bird.go = &go[0];
    bird.width = BIRD_SIZE;
    bird.height = BIRD_SIZE;

    body.go = &go[1];
    body.width = BODY_SIZE;
    body.height = BODY_SIZE;

    gn_phys_add_bird_to_field(&bird);
    gn_phys_add_body_to_field(&body);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_no_collision);
    RUN_TEST(test_collision);
    return UNITY_END();
}