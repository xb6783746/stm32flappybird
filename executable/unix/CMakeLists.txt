

add_executable(flappybird_exe
        src/main.c)

target_include_directories(
        flappybird_exe PUBLIC
        ./include
        ${GTK3_INCLUDE_DIRS}
        $<TARGET_PROPERTY:platform,INCLUDE_DIRECTORIES>
)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)


target_link_libraries(
        flappybird_exe
        engine
        platform
        graphics
        gamelogic
        ${GTK3_LIBRARIES}
)

