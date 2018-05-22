

if(PLATFORM MATCHES UNIX)

    add_subdirectory(unix)
elseif(PLATFORM MATCHES STM32F4)

    add_subdirectory(stm32f4)
endif()