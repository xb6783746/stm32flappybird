
add_subdirectory(unity)
add_subdirectory(cmock)

if(PLATFORM STREQUAL STM32F4)

    add_subdirectory(stm32/spl)
    add_subdirectory(ssd1306)
endif()