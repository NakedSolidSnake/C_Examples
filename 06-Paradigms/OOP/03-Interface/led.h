#ifndef __LED_H
#define __LED_H

#include "gpio.h"

typedef struct
{
    GPIO_t gpio;
}LED_t;

int LED_init(LED_t *led);
int LED_set(LED_t *led, eState_t eState);

#endif