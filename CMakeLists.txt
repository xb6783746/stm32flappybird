cmake_minimum_required(VERSION 3.10)
project(flappybird C ASM)

set(CMAKE_C_STANDARD 99)

include(CTest)

set(GRAPHICS_LIB SSD1306)

add_definitions(
        -DSTM32F4
)

add_subdirectory(engine)
add_subdirectory(libs)
add_subdirectory(platform)
add_subdirectory(graphics)
add_subdirectory(flappybird)
add_subdirectory(executable)