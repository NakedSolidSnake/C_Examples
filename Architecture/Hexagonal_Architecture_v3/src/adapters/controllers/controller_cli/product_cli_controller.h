#ifndef PRODUCT_CLI_CONTROLLER_H_
#define PRODUCT_CLI_CONTROLLER_H_

#include <cli/cli.h>
#include <controller_base.h>

typedef struct 
{
    product_service_base_t *base;
    cli_t cli;
} product_cli_controller_t;

bool product_cli_controller_init  (void *object);
bool product_cli_controller_open  (void *object, product_service_base_t *service_base);
bool product_cli_controller_run   (void *object);
bool product_cli_controller_close (void *object);

controller_base_t product_cli_create_base (void);


#endif /* PRODUCT_CLI_CONTROLLER_H_ */
