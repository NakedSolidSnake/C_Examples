#include "hw_interface.h"

static bool is_initialized(Interface *interface);

bool run_toogle_led(Interface *interface, int _delay)
{
    bool is_init = is_initialized(interface);
    uint8_t state = 0;
    
    if(is_init)
    {
        interface->init();

        while(true)
        {
            interface->wait(_delay);
            interface->set(state);
            state ^= 0x01;
        }
    }

    return is_init;    
}

static bool is_initialized(Interface *interface)
{
    bool is_config = true;

    if(!interface ||
       !interface->init || 
       !interface->wait ||
       !interface->set)
       {
           is_config = false;
       }
        
    return is_config;

}
