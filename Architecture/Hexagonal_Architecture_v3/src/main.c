#include <product_repository.h>
#include <service.h>
#include <stdlib.h>
#include <product_udp_controller.h>
#include <product_cli_controller.h>

int main (int argc, char *argv[])
{
    product_repository_t repository;
    product_service_t service;
    product_udp_controller_t udp_controller;
    product_cli_controller_t cli_controller;

    product_repository_init (&repository);
    product_repository_open (&repository);

    product_service_init (&service);
    product_service_open (&service, (product_repository_base_t *)&repository);

    // product_udp_controller_init (&udp_controller);
    // product_udp_controller_open (&udp_controller, (product_service_base_t *)&service);

    // product_udp_controller_run (&udp_controller);

    product_cli_controller_init (&cli_controller);
    product_cli_controller_open (&cli_controller, (product_service_base_t *)&service);

    product_cli_controller_run (&cli_controller);


    // service.base.add_product (&service, &prod);
    // service.base.get_products (&service);
    // service.base.get_product_by_id (&service, 1);
    // service.base.remove_product (&service, 1);

    return 0;
}