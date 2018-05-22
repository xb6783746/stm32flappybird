

add_executable(flappybird_exe
        src/main.c
        src/button_handler.c
        src/systimer.c
        src/system_stm32f4xx.c
        src/startup_stm32f407xx.S)

target_include_directories(
        flappybird_exe PUBLIC
        ./include
        $<TARGET_PROPERTY:platform,INCLUDE_DIRECTORIES>
)

target_link_libraries(
        flappybird_exe
        engine
        platform
        graphics
        gamelogic
)

