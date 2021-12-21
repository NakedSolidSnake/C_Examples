#ifndef SERVICE_H_
#define SERVICE_H_

#include <product_service_base.h>
#include <product_repository_base.h>

typedef struct 
{
    product_service_base_t base;
    product_repository_base_t *repository;
} product_service_t;

bool product_service_init (product_service_t *service);
bool product_service_open (product_service_t *service, product_repository_base_t *repository);
bool product_service_close (product_service_t *service);

#endif /* SERVICE_H_ */
