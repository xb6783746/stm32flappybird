
add_library(platform
        src/timer_service.c
        src/random_service.c)


target_include_directories(
        platform PUBLIC
        ./include
        ../include
)

target_link_libraries(
        platform
        spl
)
