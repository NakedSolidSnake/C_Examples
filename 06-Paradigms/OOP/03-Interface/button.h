#ifndef __BUTTON_H
#define __BUTTON_H

#include "gpio.h"

typedef void (*button_cb)(void);

typedef enum
{
    ePullModePullOff = 0,
    ePullModePullDown,
    ePullModePullUp
}ePullMode_t;

typedef enum
{
    eIntEdgeSetup = 0,
    eIntEdgeFalling,
    eIntEdgeRising,
    eIntEdgeBoth
}eIntEdge_t;

typedef struct
{
    GPIO_t gpio;
    ePullMode_t ePullMode;
    eIntEdge_t eIntEdge;
    button_cb cb;
}Button_t;

int Button_init(Button_t *button);
int Button_read(Button_t *button);

#endif