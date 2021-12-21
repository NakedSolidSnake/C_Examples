#ifndef PRODUCT_REPOSITORY_BASE_H_
#define PRODUCT_REPOSITORY_BASE_H_

#include <stdbool.h>
#include <stdint.h>
#include <product.h>

typedef struct 
{
    void *object;
    bool (*open) (void *object);
    product_t *(*get_products) (void *object);
    product_t *(*get_product_by_id) (void *object, int id);
    bool (*add_product) (void *object, const product_t *product);
    bool (*remove_product) (void *object, int id);
    bool (*close) (void *object);
} product_repository_base_t;

#endif /* PRODUCT_REPOSITORY_BASE_H_ */
