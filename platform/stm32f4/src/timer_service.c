

#include <timer_service.h>
#include <stm32f4xx.h>
#include <stm32f4_timer.h>

#define CALLBACK_BUFFER_CAPACITY 10

#define TIM_PERIOD (PWM_TIM_FREQ / TIMER_FREQUENCY)
#define TIM_PRESCALER (TIM_CLK / PWM_TIM_FREQ - 1)

typedef struct callback_array_entry_s {

    void_callback clb;
    fb_uint32_t ticks;
    fb_uint32_t curr_ticks;
} callback_array_entry_t;

static volatile fb_uint8_t flag = 0;
static callback_array_entry_t callbacks[CALLBACK_BUFFER_CAPACITY];

void TIM2_IRQHandler(void){

    if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){

        flag = 1;

        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}

void timer_service_init(){

    RCC_APB1PeriphClockCmd(TIM_RCC, ENABLE);

    TIM_TimeBaseInitTypeDef timerInit;

    timerInit.TIM_Period = TIM_PERIOD;
    timerInit.TIM_Prescaler = TIM_PRESCALER;
    timerInit.TIM_ClockDivision = 0;
    timerInit.TIM_CounterMode = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM, &timerInit);

    TIM_Cmd(TIM, ENABLE);

    TIM_ITConfig(TIM, TIM_IT_Update, ENABLE);

    NVIC_InitTypeDef nvicInit;

    nvicInit.NVIC_IRQChannel = TIM_IRQ;
    nvicInit.NVIC_IRQChannelPreemptionPriority = 0;
    nvicInit.NVIC_IRQChannelSubPriority = 1;
    nvicInit.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&nvicInit);
}

void timer_service_call_periodically(void_callback clb, fb_uint32_t ticks){

    int i;
    for(i = 0; i < CALLBACK_BUFFER_CAPACITY; i++){

        if(callbacks[i].clb == FB_NULL){

            callbacks[i].clb = clb;
            callbacks[i].ticks = ticks;
            callbacks[i].curr_ticks = 0;
            break;
        }
    }
}

void timer_service_delete(void_callback clb){

    int i;
    for(i = 0; i < CALLBACK_BUFFER_CAPACITY; i++){

        if(callbacks[i].clb == clb){

            callbacks[i].clb = FB_NULL;
            break;
        }
    }
}

void stm32f4_timer_next(void){

    if(flag){

        flag = 0;

        int i;
        for(i = 0; i < CALLBACK_BUFFER_CAPACITY; i++){

            if(callbacks[i].clb != FB_NULL){

                callbacks[i].curr_ticks++;

                if(callbacks[i].curr_ticks == callbacks[i].ticks){

                    callbacks[i].curr_ticks = 0;

                    callbacks[i].clb();
                }
            }
        }
    }
}