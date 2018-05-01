

add_library(engine STATIC
        src/physics_engine.c
        src/game_field.c
        src/moving.c
        src/collision.c
        src/game_engine.c
        src/graphics_engine.c)

add_subdirectory(test)

target_include_directories(
        engine PUBLIC
        ./include
)

target_include_directories(
        engine PRIVATE
        $<TARGET_PROPERTY:platform,INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:graphics,INCLUDE_DIRECTORIES>
)


