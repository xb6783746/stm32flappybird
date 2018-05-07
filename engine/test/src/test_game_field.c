
#include <internal/game_field.h>
#include <unity.h>

#define OBJECT_COUNT 3

static gn_game_object birds_arr[OBJECT_COUNT];
static gn_game_object bodies_arr[OBJECT_COUNT];

void test_reset_field(void){

    gn_phys_reset_field();

    int i;
    for(i = 0; i < BIRDS_BUFFER_CAPACITY; i++){

        TEST_ASSERT_EQUAL(birds[i], NULL);
    }

    for(i = 0; i < SOLID_BODIES_BUFFER_CAPACITY; i++){

        TEST_ASSERT_EQUAL(bodies[i], NULL);
    }
}


void test_add_objects(void){


    gn_phys_reset_field();

    int i;
    for(i = 0; i < OBJECT_COUNT; i++){

        gn_phys_add_bird_to_field(&birds_arr[i]);
        gn_phys_add_body_to_field(&bodies_arr[i]);
    }

    for(i = 0; i < OBJECT_COUNT; i++){

        TEST_ASSERT_EQUAL_MEMORY(birds[i], &birds_arr[i], sizeof(gn_game_object));
        TEST_ASSERT_EQUAL_MEMORY(bodies[i], &bodies_arr[i], sizeof(gn_game_object));
    }

}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_reset_field);
    RUN_TEST(test_add_objects);
    return UNITY_END();
}