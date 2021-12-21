#ifndef PRODUCT_CONTROLLER_H_
#define PRODUCT_CONTROLLER_H_

#include <product_service_base.h>
#include <udp/udp.h>

typedef struct 
{
    product_service_base_t *base;
    UDP_Server server;
} product_controller_t;

bool product_controller_init (product_controller_t *controller);
bool product_controller_open (product_controller_t *controller, product_service_base_t *service_base);
bool product_controller_run (product_controller_t *controller);
bool product_controller_close (product_controller_t *controller);


#endif /* PRODUCT_CONTROLLER_H_ */
