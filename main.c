#include "main.h"

#include "gpio.h"

static uint16_t __timer = 0;

void Delay(uint16_t n)
{
    __timer = n;
    while (__timer > 0);
}

int main()
{

    GPIOInitPin(GPIOE, 15, GPIO_DIR_OUTPUT | GPIO_OUTPUT_PP | GPIO_SPEED_HIGH);
    GPIOInitPin(GPIOE, 14, GPIO_DIR_INPUT | GPIO_PULL_UP);

    if (SysTick_Config(SystemCoreClock / 1000))
    { 
        while (1);
    }

    while (1) {
        if (GPIOReadPin(GPIOE, 14))
        {
            GPIOTogglePin(GPIOE, 15);
        }
        Delay(100);
    }
}

void Timer_Decrement()
{
    if (__timer > 0)
        __timer--;
} 

void assert_param(int x)
{

}
