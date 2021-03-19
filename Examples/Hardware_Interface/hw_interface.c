#include "hw_interface.h"

static bool hw_is_initialized(hw_interface *interface);

bool hw_run_toogle_led(hw_interface *interface, uint16_t seconds)
{
    bool is_init = hw_is_initialized(interface);
    uint8_t state = 0;

    if (is_init)
    {
        interface->init();

        while (true)
        {
            interface->wait(seconds);
            interface->set(state);
            state ^= 0x01;
        }
    }

    return is_init;
}

static bool hw_is_initialized(hw_interface *interface)
{
    bool is_config = true;

    if (!interface ||
        !interface->init ||
        !interface->wait ||
        !interface->set)
    {
        is_config = false;
    }

    return is_config;
}
