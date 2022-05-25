#include "stm32f4xx.h"

int main(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    while (1) {
        GPIO_SetBits(GPIOB, GPIO_Pin_9);
        for(int i=0;i<10000000; i++){
            __asm("nop");
        }

        GPIO_ResetBits(GPIOB, GPIO_Pin_9);
        for(int i=0;i<10000000; i++){
            __asm("nop");
        }
    }
}
