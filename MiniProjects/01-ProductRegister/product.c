#include "product.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product
{
    int id;
    char name[NAME_LEN + 1];
    char description[DESCRIPTION_LEN + 1];
    double price;
};

static int id = 0;

Product *Product_create(const char *name, const char *description, double price)
{
    Product *product = (Product *)malloc(sizeof(Product));
    if(product)
    {
        product->id = ++id;
        strncpy(product->name, name, NAME_LEN + 1);
        strncpy(product->description, description, DESCRIPTION_LEN + 1);
        product->price = price;
    }

    return product;
}

void Product_destroy(Product *product)
{
    free(product);
}

void Product_setId(Product *product, const int id)
{
    product->id = id;
}

void Product_setName(Product *product, const char *name)
{
    memset(product->name, 0, NAME_LEN + 1);
    strncpy(product->name, name, NAME_LEN + 1);
}
void Product_setDescription(Product *product, const char *description)
{
    memset(product->description, 0, DESCRIPTION_LEN + 1);
    strncpy(product->description, description, DESCRIPTION_LEN + 1);
}

void Product_setPrice(Product *product, const double price)
{
    product->price = price;
}

int Product_getId(const Product *product)
{
    return product->id;
}

char *Product_getName(const Product *product)
{
    return product->name;
}

char *Product_getDescription(const Product *product)
{
    return product->description;
}

double Product_getPrice(const Product *product)
{
    return product->price;
}


