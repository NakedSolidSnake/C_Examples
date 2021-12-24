#include <product_udp_controller.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_LEN      1024

static char buffer[BUFFER_LEN];

static void on_receive(const char *buffer, size_t buffer_size, void *data)
{
    product_udp_controller_t *controller = (product_udp_controller_t *)data;
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

bool product_udp_controller_init (void *object)
{
    product_udp_controller_t *controller = (product_udp_controller_t *)object;
    bool status = false;

    if (controller)
    {
        memset (controller, 0, sizeof (product_udp_controller_t));
        status = true;
    }

    return status;
}

bool product_udp_controller_open (void *object, product_service_base_t *service_base)
{
    bool status = false;
    product_udp_controller_t *controller = (product_udp_controller_t *)object;

    if (controller && service_base)
    {
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

bool product_udp_controller_run (void *object)
{
    product_udp_controller_t *controller = (product_udp_controller_t *)object;

    printf ("Server running on port %d\n", controller->server.port);

    while (true)
        UDP_Server_Run (&controller->server, controller);

    return true;
}

bool product_udp_controller_close (void *object)
{
    product_udp_controller_t *controller = (product_udp_controller_t *)object;
    bool status = false;

    if (controller)
    {
        memset (controller, 0, sizeof (product_udp_controller_t));
        status = true;
    }

    return status;
}

controller_base_t product_udp_create_base (void)
{
    static product_udp_controller_t udp_controller;
    static controller_base_t base = 
    {
        .object = &udp_controller,
        .init  = product_udp_controller_init,
        .open  = product_udp_controller_open,
        .run   = product_udp_controller_run,
        .close = product_udp_controller_close
    };

    return base;
}