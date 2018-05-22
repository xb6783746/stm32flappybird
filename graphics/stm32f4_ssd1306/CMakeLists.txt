
add_library(
        graphics STATIC
        src/ssd1306_graphics.c
)

target_include_directories(
        graphics PUBLIC
        ./include
        ../include
)

target_include_directories(
        graphics PRIVATE
        $<TARGET_PROPERTY:platform,INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:engine,INCLUDE_DIRECTORIES>
)

target_link_libraries(
        graphics
        ssd1306
)