#ifndef PRODUCT_H_
#define PRODUCT_H_

#define TYPE_LEN        100
#define DESCRIPTION_LEN 200

typedef struct 
{
    int id;
    char type[TYPE_LEN];
    char description[DESCRIPTION_LEN];
} product_t;

product_t product_create (int id, const char *type, const char *description);

#endif /* PRODUCT_H_ */
