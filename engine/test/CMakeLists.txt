
include_directories(
        ./include
        ../include
        $<TARGET_PROPERTY:platform,INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:graphics,INCLUDE_DIRECTORIES>
)

link_libraries(
        unity
)

add_executable(test_moving_app src/test_moving.c ../src/moving.c ../src/game_field.c)
add_executable(test_collision_app src/test_collision.c ../src/collision.c ../src/game_field.c)
add_executable(test_game_field_app src/test_game_field.c ../src/game_field.c)

add_test(test_moving test_moving_app)
add_test(test_collision test_collision_app)
add_test(test_game_field test_game_field_app)


