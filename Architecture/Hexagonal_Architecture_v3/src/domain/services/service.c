#include <service.h>
#include <string.h>

static bool service_open (void *object);
static product_t *service_get_products (void *object);
static product_t *service_get_product_by_id (void *object, int id);
static bool service_add_product (void *object, const product_t *product);
static bool service_remove_product (void *object, int id);
static bool service_close (void *object);

bool product_service_init (product_service_t *service)
{
    bool status = false;

    if (service)
    {
        memset (service, 0, sizeof (product_service_t));
        status = true;
    }

    return status;
}

bool product_service_open (product_service_t *service, product_repository_base_t *repository)
{
    bool status = false;

    if (service)
    {
        service->base.object = service;
        service->base.open = service_open;
        service->base.get_products = service_get_products;
        service->base.add_product = service_add_product;
        service->base.get_product_by_id = service_get_product_by_id;
        service->base.remove_product = service_remove_product;
        service->base.close = service_close;

        service->repository = repository;
        // memcpy (&service->repository, repository, sizeof (product_repository_base_t));
        
        status = true;
    }

    return status;
}

bool product_service_close (product_service_t *service)
{
    return product_service_init (service);
}

static bool service_open (void *object)
{
    return true;
}

static product_t *service_get_products (void *object)
{
    product_service_t *service = (product_service_t *)object;
    return service->repository->get_products(service->repository);
}

static product_t *service_get_product_by_id (void *object, int id)
{
    product_service_t *service = (product_service_t *)object;
    return service->repository->get_product_by_id (service->repository, id);
}

static bool service_add_product (void *object, const product_t *product)
{
    product_service_t *service = (product_service_t *)object;
    return service->repository->add_product (service->repository, product);
}

static bool service_remove_product (void *object, int id)
{
    product_service_t *service = (product_service_t *)object;
    return service->repository->remove_product (service->repository, id);
}

static bool service_close (void *object)
{
    return true;
}
