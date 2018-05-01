

add_library(gamelogic STATIC
        )

target_include_directories(
        gamelogic PUBLIC
        ./include
)

target_include_directories(
        gamelogic PRIVATE
        $<TARGET_PROPERTY:platform,INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:engine,INCLUDE_DIRECTORIES>
)

