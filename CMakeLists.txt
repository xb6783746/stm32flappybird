cmake_minimum_required(VERSION 3.10)
project(flappybird C)

set(CMAKE_C_STANDARD 99)

include(CTest)

add_subdirectory(engine)
add_subdirectory(libs)