#include <controller_factory.h>
#include <product_udp_controller.h>
#include <product_cli_controller.h>


controller_base_t controller_factory_create (controller_type_t type)
{
    controller_base_t controler;
    if (type == controller_type_udp)
    {
        controler = product_udp_create_base();
    }

    else if (type == controller_type_cli)
    {
        controler = product_cli_create_base();
    }

    return controler;
}