#include <stdio.h>
#include "Button.h"
#include <stdlib.h>

//gcc -g -fPIC -Wall -Werror -Wextra -pedantic *.c -shared -o button.so -ldl

static const char *name = "Button";

IDriver *create_plugin(void)
{    
    IDriver *driver = (IDriver *)malloc(sizeof(IDriver));     

    driver->device_name = BUTTON_name;
    driver->device_init = BUTTON_init;
    driver->device_write  = BUTTON_write;
    driver->device_read   = BUTTON_read;
    driver->device_deinit = BUTTON_deinit;
    return driver;
}

char *BUTTON_name(void)
{
    return (char *)name;
}

int BUTTON_init(void)
{
    printf("Button Init.\n");
    return 0;
}

int BUTTON_write(unsigned char state)
{
    (void)state;
    return -1;
}

int BUTTON_read(void)
{
    return rand() % 2;
}

int BUTTON_deinit(void)
{
    printf("Button Deinit.\n");
    return 0;
}