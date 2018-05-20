
include_directories(
        ./include
        ../include
        $<TARGET_PROPERTY:platform,INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:graphics,INCLUDE_DIRECTORIES>
)

link_libraries(
        unity
        cmock
)

add_executable(test_moving_app src/test_moving.c ../src/moving.c)
add_executable(test_collision_app src/test_collision.c ../src/collision.c)
add_executable(test_game_field_app src/test_game_field.c ../src/physics_engine.c)
#add_executable(test_graphics_engine_app src/test_graphics_engine.c src/mocks/Mockgraphics.c ../src/graphics_engine.c)

add_test(test_moving test_moving_app)
add_test(test_collision test_collision_app)
add_test(test_game_field test_game_field_app)
add_test(test_graphics_engine test_graphics_engine_app)

