#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>

int GPIO_init(GPIO_t *gpio)
{
    if(!gpio)
        return EXIT_FAILURE;

    printf("Initialize GPIO(%d) as %s.\n", 
            gpio->pin,gpio->eMode == eModeInput ? "INPUT" : "OUTPUT");

    return EXIT_SUCCESS;
}