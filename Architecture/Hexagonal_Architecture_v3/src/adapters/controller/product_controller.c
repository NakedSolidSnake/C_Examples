#include <product_controller.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_LEN      1024

static char buffer[BUFFER_LEN];

static void on_receive(const char *buffer, size_t buffer_size, void *data)
{
    product_controller_t *controller = (product_controller_t *)data;
    if (strncmp (buffer, "add", 3) == 0)
    {
        controller->base->add_product (controller->base, NULL);
    }

    else if (strncmp (buffer, "remove", 6) == 0)
    {
        controller->base->remove_product (controller->base, 0);
    }

    else if (strncmp (buffer, "all", 3) == 0)
    {
        controller->base->get_products (controller->base);
    }

    else if (strncmp (buffer, "by_id", 5) == 0)
    {
        controller->base->get_product_by_id (controller->base, 0);
    }
}

bool product_controller_init (product_controller_t *controller)
{
    bool status = false;

    if (controller)
    {
        memset (controller, 0, sizeof (product_controller_t));
        status = true;
    }

    return status;
}

bool product_controller_open (product_controller_t *controller, product_service_base_t *service_base)
{
    bool status = false;

    if (controller && service_base)
    {
        // memcpy (&controller->base, service_base, sizeof (product_service_base_t));
        controller->base = service_base;

        controller->server.on_receive_message = on_receive;        
        controller->server.port = 1234;
        controller->server.buffer = buffer;
        controller->server.buffer_size = BUFFER_LEN;
        UDP_Server_Init (&controller->server);
        status = true;
    }

    return status;
}

bool product_controller_run (product_controller_t *controller)
{
    while (true)
        UDP_Server_Run (&controller->server, controller);
}

bool product_controller_close (product_controller_t *controller)
{
    return product_controller_init (controller);
}