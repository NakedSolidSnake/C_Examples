#include <stdio.h>
#include "LED.h"
#include <stdlib.h>

//gcc -g -fPIC -Wall -Werror -Wextra -pedantic *.c -shared -o led.so -ldl

static const char *name = "LED";

IDriver *create_plugin(void)
{    
    IDriver *driver = (IDriver *)malloc(sizeof(IDriver));    

    driver->device_name   = LED_name;
    driver->device_init   = LED_init;
    driver->device_write  = LED_write;
    driver->device_read   = LED_read;
    driver->device_deinit = LED_deinit;
    return driver;
}

char *LED_name(void)
{
    return (char *)name;
}

int LED_init(void)
{
    printf("LED Init.\n");
    return 0;
}

int LED_write(unsigned char state)
{
    printf("LED State %d.\n", state);
    return 0;
}

int LED_read(void)
{
    return 0;    
}

int LED_deinit(void)
{
    printf("LED Deinit.\n");
    return 0;
}