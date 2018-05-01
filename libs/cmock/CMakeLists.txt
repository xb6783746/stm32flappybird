

add_library(cmock STATIC src/cmock.c)

target_include_directories(
        cmock PUBLIC
        src
)

target_link_libraries(
        cmock
        unity
)