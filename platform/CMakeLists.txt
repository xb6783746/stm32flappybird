

if(PLATFORM MATCHES STM32F4)

    add_subdirectory(stm32f4)
elseif(PLATFORM MATCHES UNIX)

    add_subdirectory(unix)
endif()

