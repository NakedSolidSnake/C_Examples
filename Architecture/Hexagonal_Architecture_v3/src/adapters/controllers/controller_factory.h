#ifndef CONTROLLER_FACTORY_H_
#define CONTROLLER_FACTORY_H_

#include <controller_base.h>

typedef enum 
{
    controller_type_udp,
    controller_type_cli
} controller_type_t;

typedef struct 
{
    controller_base_t base;    
} controller_t;

controller_t controller_create (controller_type_t type);


#endif /* CONTROLLER_FACTORY_H_ */
