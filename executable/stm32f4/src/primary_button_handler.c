
#include <systimer.h>
#include <platform.h>

#define BUTTON_DELAY_MS 1000

extern uint32_t systimer_timestamp;
static uint32_t delay = 0;
volatile fb_uint8_t primary_button_flag = 0;

void EXTI0_IRQHandler(void) {

    if (EXTI_GetITStatus(EXTI_Line0) != RESET){

        EXTI_ClearITPendingBit(EXTI_Line0);

        if(delay > systimer_timestamp){

            return;
        }

        delay = systimer_timestamp + BUTTON_DELAY_MS;

        primary_button_flag = 1;
    }
}