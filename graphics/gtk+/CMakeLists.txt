

add_library(graphics STATIC
        src/gtk_graphics.c
        src/graphics_engine_internal.c)

target_include_directories(
        graphics PUBLIC
        ./include
        ../include
)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)


target_include_directories(
        graphics PRIVATE
        $<TARGET_PROPERTY:platform,INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:engine,INCLUDE_DIRECTORIES>
        ${GTK3_INCLUDE_DIRS}
)

