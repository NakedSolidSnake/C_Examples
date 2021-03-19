#include "hw_interface.h"
#include <stdio.h>
#include <unistd.h>

/* Functions to use in the interface */
static void pc_init(void);
static void pc_wait(uint16_t seconds);
static void pc_set(uint8_t state);

int main(void)
{
    hw_interface interface =
    {
        .init = pc_init,
        .wait = pc_wait,
        .set = pc_set
    };

    if (hw_run_toogle_led(&interface, 1) == false)
        printf("Error.\n");
}

static void pc_init(void)
{
    printf("Init.\n");
}

static void pc_wait(uint16_t seconds)
{
    sleep(seconds);
}

static void pc_set(uint8_t state)
{
    printf("state = %d\n", state);
}