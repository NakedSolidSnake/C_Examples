#include <controller_factory.h>
#include <product_udp_controller.h>
#include <product_cli_controller.h>


controller_t controller_create (controller_type_t type)
{
    controller_t controler;
    if (type == controller_type_udp)
    {
        controler.base = product_udp_create_base();
    }

    else if (type == controller_type_cli)
    {
        controler.base = product_cli_create_base();
    }

    return controler;
}