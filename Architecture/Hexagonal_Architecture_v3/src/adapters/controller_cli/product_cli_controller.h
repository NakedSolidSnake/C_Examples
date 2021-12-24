#ifndef PRODUCT_CLI_CONTROLLER_H_
#define PRODUCT_CLI_CONTROLLER_H_

#include <product_service_base.h>
#include <cli/cli.h>

typedef struct 
{
    product_service_base_t *base;
    cli_t cli;
} product_cli_controller_t;

bool product_cli_controller_init  (product_cli_controller_t *controller);
bool product_cli_controller_open  (product_cli_controller_t *controller, product_service_base_t *service_base);
bool product_cli_controller_run   (product_cli_controller_t *controller);
bool product_cli_controller_close (product_cli_controller_t *controller);


#endif /* PRODUCT_CLI_CONTROLLER_H_ */
