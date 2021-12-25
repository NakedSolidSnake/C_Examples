#include <product_repository.h>
#include <controller_factory.h>
#include <service.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    product_repository_t repository;
    product_service_t service;
    controller_base_t controller;
    
    product_repository_init (&repository);
    product_repository_open (&repository);

    product_service_init (&service);
    product_service_open (&service, (product_repository_base_t *)&repository);

    controller = controller_factory_create (controller_type_udp);
    controller.init (controller.object);
    controller.open (controller.object, (product_service_base_t *)&service);
    controller.run (controller.object);

    return 0;
}