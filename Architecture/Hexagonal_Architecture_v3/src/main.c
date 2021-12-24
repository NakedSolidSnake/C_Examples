#include <product_repository.h>
#include <service.h>
#include <stdlib.h>
#include <controller_factory.h>

int main (int argc, char *argv[])
{
    product_repository_t repository;
    product_service_t service;
    
    product_repository_init (&repository);
    product_repository_open (&repository);

    product_service_init (&service);
    product_service_open (&service, (product_repository_base_t *)&repository);

    controller_t controller = controller_create (controller_type_udp);
    controller.base.init (controller.base.object);
    controller.base.open (controller.base.object, (product_service_base_t *)&service);
    controller.base.run (controller.base.object);

    return 0;
}