
add_library(platform
        src/timer_service.c
        src/random_service.c)

add_definitions(
        -DUSE_PWM_TIM1
)

target_include_directories(
        platform PUBLIC
        ./include
        ../include
)

target_link_libraries(
        platform
        spl
)
