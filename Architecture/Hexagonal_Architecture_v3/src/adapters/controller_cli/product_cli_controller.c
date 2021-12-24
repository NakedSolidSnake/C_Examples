#include <product_cli_controller.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

cli_option_t option_list[] = 
{
    {.index = 1, .text = "Add"},
    {.index = 2, .text = "Remove"},
    {.index = 3, .text = "All"},
    {.index = 4, .text = "Find by id"},
};

static void *on_selected (uint8_t index, void *data)
{
    product_cli_controller_t *controller = (product_cli_controller_t *)data;

    switch (index)
    {
    case 1:
        controller->base->add_product (controller->base, NULL);
        break;

    case 2:
        controller->base->remove_product (controller->base, 0);
        break;

    case 3:
        controller->base->get_products (controller->base);
        break;

    case 4:
        controller->base->get_product_by_id (controller->base, 0);
        break;
    
    default:
        break;
    }
    return NULL;
}

bool product_cli_controller_init (product_cli_controller_t *controller)
{
    bool status = false;

    if (controller)
    {
        memset (controller, 0, sizeof (product_cli_controller_t));
        cli_init (&controller->cli);
        status = true;
    }

    return status;
}

bool product_cli_controller_open (product_cli_controller_t *controller, product_service_base_t *service_base)
{
    bool status = false;

    if (controller && service_base)
    {
        controller->base = service_base;
        controller->cli.on_selected = on_selected;        
        cli_open (&controller->cli, option_list, sizeof (option_list) / sizeof (option_list[0]));
        status = true;
    }

    return status;
}

bool product_cli_controller_run (product_cli_controller_t *controller)
{
    cli_run (&controller->cli, controller);
    return true;
}

bool product_cli_controller_close (product_cli_controller_t *controller)
{
    return product_cli_controller_init (controller);
}