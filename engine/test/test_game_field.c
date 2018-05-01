
#include <internal/game_field.h>
#include <unity.h>

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

    gn_bird_t birds_arr[3];
    gn_solid_body_t bodies_arr[3];

    int i;
    for(i = 0; i < 3; i++){

        gn_phys_add_bird_to_field(&birds_arr[i]);
        gn_phys_add_body_to_field(&bodies_arr[i]);
    }

    for(i = 0; i < 3; i++){

        TEST_ASSERT_EQUAL(birds[i], &birds_arr[i]);
        TEST_ASSERT_EQUAL(bodies[i], &bodies_arr[i]);
    }

}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_reset_field);
    RUN_TEST(test_add_objects);
    return UNITY_END();
}