

add_library(engine STATIC
        src/moving.c
        src/collision.c
        src/physics_engine.c)

#add_subdirectory(test)

target_include_directories(
        engine PUBLIC
        ./include
)

target_include_directories(
        engine PRIVATE
        $<TARGET_PROPERTY:graphics,INCLUDE_DIRECTORIES>
)


