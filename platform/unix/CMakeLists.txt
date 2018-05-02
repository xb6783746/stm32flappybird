
add_library(platform
        src/timer_service.c
        src/random_service.c)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

target_include_directories(
        platform PUBLIC
        ./include
        ../include
        ${GTK3_INCLUDE_DIRS}
)

