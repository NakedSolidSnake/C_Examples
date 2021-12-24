#ifndef CONTROLLER_BASE_H_
#define CONTROLLER_BASE_H_

#include <stdbool.h>
#include <product_service_base.h>

typedef struct 
{
    void *object;
    bool (*init) (void *object);
    bool (*open) (void *object, product_service_base_t *service_base);
    bool (*run) (void *object);
    bool (*close) (void *object);
} controller_base_t;



#endif /* CONTROLLER_BASE_H_ */
