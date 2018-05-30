

add_library(engine STATIC
        src/moving.c
        src/collision.c
        src/physics_engine.c)

if (PLATFORM MATCHES UNIX)

    add_subdirectory(test)
endif ()

target_include_directories(
        engine PUBLIC
        ./include
)

target_include_directories(
        engine PRIVATE
        $<TARGET_PROPERTY:graphics,INCLUDE_DIRECTORIES>
)


