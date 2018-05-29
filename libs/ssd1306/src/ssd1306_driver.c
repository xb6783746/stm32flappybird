
#include <ssd1306_driver.h>

//High - not selected
#define CS_HIGH() GPIO_WriteBit(SSD1306_CS_Port, SSD1306_CS_Pin, Bit_SET)
#define CS_LOW() GPIO_WriteBit(SSD1306_CS_Port, SSD1306_CS_Pin, Bit_RESET)

#define DC_HIGH() GPIO_WriteBit(SSD1306_DC_Port, SSD1306_DC_Pin, Bit_SET)
#define DC_LOW() GPIO_WriteBit(SSD1306_DC_Port, SSD1306_DC_Pin, Bit_RESET)

#define RESET_LOW()  GPIO_WriteBit(SSD1306_Reset_Port, SSD1306_Reset_Pin, Bit_RESET)
#define RESET_HIGH() GPIO_WriteBit(SSD1306_Reset_Port, SSD1306_Reset_Pin, Bit_SET);

static uint8_t buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];


static void send_byte(uint8_t data){

    SPI_I2S_SendData(SSD1306_SPI_PORT, data);
    while(SPI_I2S_GetFlagStatus(SSD1306_SPI_PORT, SPI_I2S_FLAG_BSY) == SET);
}

static void send_data(uint8_t *data, uint16_t size){

    CS_LOW();
    DC_HIGH();

    int i;
    for(i = 0; i < size; i++){

        send_byte(data[i]);
    }

    CS_HIGH();
}

void ssd1306_driver_init(){

    ssd1306_driver_reset();

    ssd1306_driver_send_command(0xAE); //display off

    ssd1306_driver_send_command(0x20); //Set Memory Addressing Mode
    ssd1306_driver_send_command(0x10); // 00,Horizontal Addressing Mode; 01,Vertical Addressing Mode;
    // 10,Page Addressing Mode (RESET); 11,Invalid

    ssd1306_driver_send_command(0xB0); //Set Page Start Address for Page Addressing Mode,0-7

    ssd1306_driver_send_command(0xC8); //Set COM Output Scan Direction

    ssd1306_driver_send_command(0x00); //---set low column address
    ssd1306_driver_send_command(0x10); //---set high column address

    ssd1306_driver_send_command(0x40); //--set start line address - CHECK

    ssd1306_driver_send_command(0x81); //--set contrast control register - CHECK
    ssd1306_driver_send_command(0xFF);

    ssd1306_driver_send_command(0xA1); //--set segment re-map 0 to 127 - CHECK

    ssd1306_driver_send_command(0xA6); //--set normal color

    ssd1306_driver_send_command(0xA8); //--set multiplex ratio(1 to 64) - CHECK
    ssd1306_driver_send_command(0x3F); //

    ssd1306_driver_send_command(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content

    ssd1306_driver_send_command(0xD3); //-set display offset - CHECK
    ssd1306_driver_send_command(0x00); //-not offset

    ssd1306_driver_send_command(0xD5); //--set display clock divide ratio/oscillator frequency
    ssd1306_driver_send_command(0xF0); //--set divide ratio

    ssd1306_driver_send_command(0xD9); //--set pre-charge period
    ssd1306_driver_send_command(0x22); //

    ssd1306_driver_send_command(0xDA); //--set com pins hardware configuration - CHECK
    ssd1306_driver_send_command(0x12);

    ssd1306_driver_send_command(0xDB); //--set vcomh
    ssd1306_driver_send_command(0x20); //0x20,0.77xVcc

    ssd1306_driver_send_command(0x8D); //--set DC-DC enable
    ssd1306_driver_send_command(0x14); //
    ssd1306_driver_send_command(0xAF); //--turn on SSD1306 panel

    ssd1306_driver_fill(Ssd1306_Black);

    ssd1306_driver_update();

}

void ssd1306_driver_reset(){

    CS_HIGH();

    RESET_LOW();
    RESET_HIGH();
    
}

void ssd1306_driver_send_command(uint8_t command){

    CS_LOW();
    DC_LOW();

    send_byte(command);

    CS_HIGH();
}

void ssd1306_driver_fill(ssd1306_pixel_t val){

    uint32_t i;
    for(i = 0; i < sizeof(buffer); i++) {
        buffer[i] = val;
    }
}

void ssd1306_driver_fill_region(int16_t x, int16_t y, uint8_t width, uint8_t height, ssd1306_pixel_t val){

    int16_t i, j;
    for(i = x; i < x + width; i++){

        for(j = y; j < y + height; j++){

            ssd1306_driver_set_pixel(i, j, val);
        }
    }
}

void ssd1306_driver_set_pixel(uint8_t x, uint8_t y, ssd1306_pixel_t val){

    if(x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) {

        return;
    }

    if(val == Ssd1306_White) {
        buffer[x + (y / 8) * SSD1306_WIDTH] |= 1 << (y % 8);
    } else {
        buffer[x + (y / 8) * SSD1306_WIDTH] &= ~(1 << (y % 8));
    }
}

void ssd1306_driver_update(){

    uint8_t i;
    for(i = 0; i < 8; i++) {
        ssd1306_driver_send_command(0xB0 + i);
        ssd1306_driver_send_command(0x00);
        ssd1306_driver_send_command(0x10);
        send_data(&buffer[SSD1306_WIDTH*i],SSD1306_WIDTH);
    }
}