
#include <stdint.h>

#include "stm32f30x.h"

#include "gpio.h"


void GPIOInitPin(GPIO_TypeDef* port, uint8_t pin, uint32_t config)
{
   port->MODER = (port->MODER & ~(GPIO_MODER_MODER0 << (pin * 2))) | ((config & GPIO_DIR_MASK) << (pin * 2));

   port->OTYPER = (port->OTYPER & ~(1 << pin)) | (((config & GPIO_OUTPUT_MASK) >> 1) << pin);

   port->OSPEEDR = (port->OSPEEDR & ~(GPIO_OSPEEDER_OSPEEDR0 << (pin * 2))) | (((config & GPIO_SPEED_MASK) >> 5) << (pin * 2));

   port->PUPDR = (port->PUPDR & ~(GPIO_PUPDR_PUPDR0 << (pin * 2))) | (((config & GPIO_PULL_MASK) >> 3) << (pin * 2));

   if (pin <= 7)
   {
      port->AFR[0] = (port->AFR[0] & ~(GPIO_AFRL_AFRL0 << (pin * 4))) | (((config & GPIO_AF_MASK) >> 16) << (pin * 4));
   } else {
      port->AFR[1] = (port->AFR[1] & ~(GPIO_AFRH_AFRH0 << ((pin-8) * 4))) | (((config & GPIO_AF_MASK) >> 16) << ((pin-8) * 4));
   }
}

void GPIOSetPin(GPIO_TypeDef* port, uint8_t pin)
{
   port->BSRR |= (1 << pin);
}

void GPIOResetPin(GPIO_TypeDef* port, uint8_t pin)
{
   port->BRR |= (1 << pin);
}

void GPIOWritePin(GPIO_TypeDef* port, uint8_t pin, uint8_t val)
{
   if (val)
   {
      GPIOSetPin(port, pin);
   } else {
      GPIOResetPin(port, pin);
   }
}

void GPIOTogglePin(GPIO_TypeDef* port, uint8_t pin)
{
   port->ODR ^= (1 << pin);
}

uint8_t GPIOReadPin(GPIO_TypeDef* port, uint8_t pin)
{
   return (port->IDR >> pin) & 1;
}

