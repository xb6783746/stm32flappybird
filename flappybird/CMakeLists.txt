

add_library(gamelogic STATIC
        src/flappybird.c
        src/object_buffer.c
        src/game_object_factory.c
        src/engine_event_handler.c)

target_include_directories(
        gamelogic PUBLIC
        ./include
)

target_include_directories(
        gamelogic PRIVATE
        $<TARGET_PROPERTY:platform,INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:engine,INCLUDE_DIRECTORIES>
)

