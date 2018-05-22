

#ifndef SSD1306_DRIVER_H
#define SSD1306_DRIVER_H

#include <stm32f4xx.h>

#define SSD1306_SPI_PORT        SPI1

#define SSD1306_CS_Port         GPIOB
#define SSD1306_CS_Pin          GPIO_Pin_12

#define SSD1306_DC_Port         GPIOB
#define SSD1306_DC_Pin          GPIO_Pin_14

#define SSD1306_Reset_Port      GPIOA
#define SSD1306_Reset_Pin       GPIO_Pin_8

#define SSD1306_HEIGHT          64
#define SSD1306_WIDTH           128


typedef enum ssd1306_pixel_s{
    Ssd1306_White = 0xFF, Ssd1306_Black = 0x00
} ssd1306_pixel_t;


void ssd1306_driver_init();
void ssd1306_driver_reset();
void ssd1306_driver_send_command(uint8_t command);
void ssd1306_driver_fill(ssd1306_pixel_t val);
void ssd1306_driver_fill_region(int16_t x, int16_t y, uint8_t width, uint8_t height, ssd1306_pixel_t val);
void ssd1306_driver_set_pixel(uint8_t x, uint8_t y, ssd1306_pixel_t val);
void ssd1306_driver_update();

void ssd1306_driver_set_tmp(uint8_t x, uint8_t y, ssd1306_pixel_t val);

#endif //SSD1306_DRIVER_H
