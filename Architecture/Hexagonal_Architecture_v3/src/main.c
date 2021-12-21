#include <product_repository.h>
#include <service.h>
#include <stdlib.h>
#include <product_controller.h>

int main (int argc, char *argv[])
{
    product_repository_t repository;
    product_service_t service;
    product_controller_t controller;
    product_t prod;

    product_repository_init (&repository);
    product_repository_open (&repository);

    product_service_init (&service);
    product_service_open (&service, (product_repository_base_t *)&repository);

    product_controller_init (&controller);
    product_controller_open (&controller, (product_service_base_t *)&service);

    product_controller_run (&controller);


    // service.base.add_product (&service, &prod);
    // service.base.get_products (&service);
    // service.base.get_product_by_id (&service, 1);
    // service.base.remove_product (&service, 1);

    return 0;
}