#ifndef __SIMPLE_GPIO__
#define __SIMPLE_GPIO__

#include <stdint.h>


#define GPIO_DIR_MASK   (3 << 0)
#define GPIO_DIR_INPUT  (0 << 0)
#define GPIO_DIR_OUTPUT (1 << 0)
#define GPIO_DIR_AF     (2 << 0)

#define GPIO_OUTPUT_MASK (1 << 2)
#define GPIO_OUTPUT_PP  (0 << 2)
#define GPIO_OUTPUT_OD  (1 << 2)

#define GPIO_PULL_MASK  (3 << 3)
#define GPIO_PULL_NONE  (0 << 3)
#define GPIO_PULL_UP    (1 << 3)
#define GPIO_PULL_DOWN  (2 << 3)

#define GPIO_SPEED_MASK (3 << 5)
#define GPIO_SPEED_LOW  (0 << 5)
#define GPIO_SPEED_MED  (2 << 5)
#define GPIO_SPEED_HIGH (3 << 5)

#define GPIO_AF_MASK    (0xF << 16)
#define GPIO_AF0        (0 << 16)
#define GPIO_AF1        (1 << 16)
#define GPIO_AF2        (2 << 16)
#define GPIO_AF3        (3 << 16)
#define GPIO_AF4        (4 << 16)
#define GPIO_AF5        (5 << 16)
#define GPIO_AF6        (6 << 16)
#define GPIO_AF7        (7 << 16)
#define GPIO_AF8        (8 << 16)
#define GPIO_AF9        (9 << 16)
#define GPIO_AF10       (10 << 16)
#define GPIO_AF11       (11 << 16)
#define GPIO_AF12       (12 << 16)
#define GPIO_AF13       (13 << 16)
#define GPIO_AF14       (14 << 16)
#define GPIO_AF15       (15 << 16)


void GPIOInitPin(GPIO_TypeDef* port, uint8_t pin, uint32_t config);
void GPIOSetPin(GPIO_TypeDef* port, uint8_t pin);
void GPIOResetPin(GPIO_TypeDef* port, uint8_t pin);
void GPIOTogglePin(GPIO_TypeDef* port, uint8_t pin);
void GPIOWritePin(GPIO_TypeDef* port, uint8_t pin, uint8_t val);
uint8_t GPIOReadPin(GPIO_TypeDef* port, uint8_t pin);

#endif