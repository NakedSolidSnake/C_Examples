#include "led.h"
#include "button.h"
#include <stdio.h>
#include <stdlib.h>

static void inputHandler(void);

int main(int argc, char const *argv[])
{
    LED_t led = 
    {
        .gpio.pin = 5,
        .gpio.eMode = eModeOutput
    };

    Button_t button7 = {
        .gpio.pin = 7,
        .gpio.eMode = eModeInput,
        .ePullMode = ePullModePullUp,
        .eIntEdge = eIntEdgeFalling,
        .cb = inputHandler
    };

    LED_init(&led);
    LED_set(&led, eStateHigh);

    Button_init(&button7);

    printf("Button State: %d.\n", Button_read(&button7));

    return EXIT_SUCCESS;
}

static void inputHandler(void)
{
    printf("Call event.\n");
}