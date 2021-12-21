#ifndef PRODUCT_REPOSITORY_H_
#define PRODUCT_REPOSITORY_H_

#include <product_repository_base.h>
#include <stdbool.h>

typedef struct 
{
    product_repository_base_t base;
} product_repository_t;

bool product_repository_init (product_repository_t *repository);
bool product_repository_open (product_repository_t *repository);
bool product_repository_close (product_repository_t *repository);

#endif /* PRODUCT_REPOSITORY_H_ */
