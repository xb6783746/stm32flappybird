

if(${GRAPHICS_LIB} MATCHES GTK+)

    add_subdirectory(gtk+)
elseif(${GRAPHICS_LIB} MATCHES SSD1306)

    add_subdirectory(stm32f4_ssd1306)
endif()