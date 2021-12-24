#ifndef PRODUCT_UDP_CONTROLLER_H_
#define PRODUCT_UDP_CONTROLLER_H_

#include <controller_base.h>
#include <product_service_base.h>
#include <udp/udp.h>

typedef struct 
{
    product_service_base_t *base;
    UDP_Server server;
} product_udp_controller_t;

bool product_udp_controller_init  (void *object);
bool product_udp_controller_open  (void *object, product_service_base_t *service_base);
bool product_udp_controller_run   (void *object);
bool product_udp_controller_close (void *object);

controller_base_t product_udp_create_base (void);

#endif /* PRODUCT_UDP_CONTROLLER_H_ */
