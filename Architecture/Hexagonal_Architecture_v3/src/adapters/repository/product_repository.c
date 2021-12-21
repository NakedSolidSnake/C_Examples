#include <product_repository.h>
#include <string.h>
#include <stdio.h>

static bool repository_open (void *object);
static product_t *repository_get_products (void *object);
static product_t *repository_get_product_by_id (void *object, int id);
static bool repository_add_product (void *object, const product_t *product);
static bool repository_remove_product (void *object, int id);
static bool repository_close (void *object);

bool product_repository_init (product_repository_t *repository)
{
    bool status = false;

    if (repository)
    {
        memset (repository, 0, sizeof (product_repository_t));
        status = true;
    }

    return status;
}

bool product_repository_open (product_repository_t *repository)
{
    bool status = false;

    if (repository)
    {
        repository->base.open = repository_open;
        repository->base.get_products = repository_get_products;
        repository->base.get_product_by_id = repository_get_product_by_id;
        repository->base.add_product = repository_add_product;
        repository->base.remove_product = repository_remove_product;
        repository->base.close = repository_close;
        status = true;
    }

    return status;
}

bool product_repository_close (product_repository_t *repository)
{
    return product_repository_init (repository);
}


static bool repository_open (void *object)
{
    return true;
}

static product_t *repository_get_products (void *object)
{
    static product_t prod;
    printf ("repository_get_products\n");
    return &prod;
}

static product_t *repository_get_product_by_id (void *object, int id)
{
    static product_t prod;
    printf ("repository_get_product_by_id\n");
    return &prod;
}

static bool repository_add_product (void *object, const product_t *product)
{
    printf ("repository_add_product\n");
    return true;
}

static bool repository_remove_product (void *object, int id)
{
    printf ("repository_remove_product\n");
    return true;
}

static bool repository_close (void *object)
{
    return true;
}