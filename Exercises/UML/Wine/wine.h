#ifndef __WINE_H
#define __WINE_H

#define WINE_NAME_LEN       80
#define WINE_TYPE_LEN       80

#include <stdbool.h>

typedef struct 
{
    char name[WINE_NAME_LEN];
    char type[WINE_TYPE_LEN];
    double price;
    int harvest;
}Wine;

char *showWine(const Wine *wine);
bool verifyPrice(double price);

#endif