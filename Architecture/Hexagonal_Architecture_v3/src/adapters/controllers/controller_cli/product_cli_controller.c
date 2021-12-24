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

bool product_cli_controller_init (void *object)
{
    product_cli_controller_t *controller = (product_cli_controller_t *)object;
    bool status = false;

    if (controller)
    {
        memset (controller, 0, sizeof (product_cli_controller_t));
        cli_init (&controller->cli);
        status = true;
    }

    return status;
}

bool product_cli_controller_open (void *object, product_service_base_t *service_base)
{
    product_cli_controller_t *controller = (product_cli_controller_t *)object;
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

bool product_cli_controller_run (void *object)
{
    product_cli_controller_t *controller = (product_cli_controller_t *)object;
    cli_run (&controller->cli, controller);
    return true;
}

bool product_cli_controller_close (void *object)
{
    product_cli_controller_t *controller = (product_cli_controller_t *)object;
     bool status = false;

    if (controller)
    {
        memset (controller, 0, sizeof (product_cli_controller_t));        
        status = true;
    }

    return status;

}

controller_base_t product_cli_create_base (void)
{
    static product_cli_controller_t cli_controller;
    static controller_base_t base = 
    {
        .object = &cli_controller,
        .init  = product_cli_controller_init,
        .open  = product_cli_controller_open,
        .run   = product_cli_controller_run,
        .close = product_cli_controller_close
    };

    return base;
}