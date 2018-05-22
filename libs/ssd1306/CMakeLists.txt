
add_library(
        ssd1306 STATIC
        src/ssd1306_driver.c
)

target_include_directories(
        ssd1306 PUBLIC
        include
)

add_definitions(
        -DSTM32F4
)
target_link_libraries(
        ssd1306
        spl
)


