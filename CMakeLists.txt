cmake_minimum_required(VERSION 3.7.2)
project(flappybird C ASM)

set(CMAKE_C_STANDARD 99)

include(CTest)

if(NOT GRAPHICS_LIB)

    set(GRAPHICS_LIB SSD1306)
endif()

add_subdirectory(engine)
add_subdirectory(libs)
add_subdirectory(platform)
add_subdirectory(graphics)
add_subdirectory(flappybird)
add_subdirectory(executable)