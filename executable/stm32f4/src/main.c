
#include <timer_service.h>
#include <flappybird.h>
#include <stm32f4_timer.h>
#include <stm32f4xx_spi.h>
#include <systimer.h>
#include <flappybird_events.h>

extern fb_uint8_t button_flag;

static void game_init();
static void on_game_over(fb_uint8_t bird_num);

static void init_spi();
static void init_gpio();
static void init_button();

int main(void)
{
    systimer_init();

    init_spi();
    init_gpio();
    init_button();

    timer_service_init();
    game_init();

    fb_game_start();

    while (1) {

        stm32f4_timer_next();

        if(button_flag){

            button_flag = 0;

            fb_bird_jump(0);
        }
    }

}

static void init_spi(){

    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_6 | GPIO_Pin_5;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    SPI_InitTypeDef spi;

    spi.SPI_Direction = SPI_Direction_1Line_Tx;
    spi.SPI_Mode = SPI_Mode_Master;
    spi.SPI_DataSize = SPI_DataSize_8b;
    spi.SPI_NSS = SPI_NSS_Soft;
    spi.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
    spi.SPI_CRCPolynomial = 10;
    spi.SPI_CPOL = SPI_CPOL_Low;
    spi.SPI_CPHA = SPI_CPHA_1Edge;
    spi.SPI_FirstBit = SPI_FirstBit_MSB;

    SPI_Init(SPI1, &spi);
    SPI_Cmd(SPI1, ENABLE);

    SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);
}
static void init_gpio(){

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef port;

    port.GPIO_Mode = GPIO_Mode_OUT;
    port.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_14;
    port.GPIO_Speed = GPIO_Speed_50MHz;
    port.GPIO_OType = GPIO_OType_PP;
    port.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &port);

    port.GPIO_Pin = GPIO_Pin_8;
    GPIO_Init(GPIOA, &port);

    port.GPIO_Mode = GPIO_Mode_OUT;
    port.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOA, &port);

    GPIO_SetBits(GPIOB, GPIO_Pin_14);
}

static void init_button(){

    GPIO_InitTypeDef port;

    port.GPIO_Mode = GPIO_Mode_IN;
    port.GPIO_Pin = GPIO_Pin_0;
    port.GPIO_Speed = GPIO_Speed_50MHz;
    port.GPIO_OType = GPIO_OType_PP;
    port.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &port);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

    EXTI_InitTypeDef EXTI_InitStruct;

    EXTI_InitStruct.EXTI_Line = EXTI_Line0;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&EXTI_InitStruct);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);
}

static void game_init(){

    fb_game_settings_t settings;

    settings.on_game_over = on_game_over;
    settings.screen_width = 128;
    settings.screen_height = 64;
    settings.birds_count = 1;

    fb_game_init(settings);

}

static void on_game_over(fb_uint8_t bird_num){

    fb_game_stop();
}
