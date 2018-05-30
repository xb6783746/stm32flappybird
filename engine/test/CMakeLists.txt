
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

add_executable(test_collision_app src/test_collision.c ../src/collision.c)

add_test(test_collision test_collision_app)

