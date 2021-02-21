#ifndef PRODUCT_H_
#define PRODUCT_H_

#define NAME_MAX_LEN            255
#define DESCRIPTION_MAX_LEN     512

typedef struct 
{
    int id;
    char name[NAME_MAX_LEN];
    char description[DESCRIPTION_MAX_LEN];
    double price;
    int amount;
} Product;

#endif /* PRODUCT_H_ */
