#include "button.h"
#include <stdio.h>
#include <stdlib.h>

int Button_init(Button_t *button)
{
    if(!button)
        return EXIT_FAILURE;

    GPIO_init((GPIO_t *)&button);

    printf("pullMode: %d, interrupt edge %d, address callback %p.\n",
        button->ePullMode, button->eIntEdge, button->cb);

    return EXIT_SUCCESS;
}

int Button_read(Button_t *button)
{
    if(!button)
        return EXIT_FAILURE;

    return (int)eStateHigh;
}