#include "led.h"
#include <stdio.h>
#include <stdlib.h>

int LED_init(LED_t *led)
{
    if(!led)
        return EXIT_FAILURE;

    return GPIO_init((GPIO_t *)&led->gpio);    
}

int LED_set(LED_t *led, eState_t eState)
{
    if(!led)
        return EXIT_FAILURE;

    printf("Set LED(%d) to state %s.\n",
            led->gpio.pin, eState == eStateLow ? "LOW" : "HIGH");

    return EXIT_SUCCESS;
}