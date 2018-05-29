
add_library(
        graphics STATIC
        src/ssd1306_graphics.c
)

target_include_directories(
        graphics PUBLIC
        ./include
        ../include
)


target_link_libraries(
        graphics
        platform
        engine
        ssd1306
)