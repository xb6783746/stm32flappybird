

add_library(graphics STATIC
        )

target_include_directories(
        graphics PUBLIC
        ./include
)

target_include_directories(
        graphics PRIVATE
        $<TARGET_PROPERTY:platform,INCLUDE_DIRECTORIES>
)

