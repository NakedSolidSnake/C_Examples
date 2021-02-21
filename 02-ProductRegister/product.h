#ifndef PRODUCT_H_
#define PRODUCT_H_

#define DESCRIPTION_LEN     120
#define NAME_LEN            120

typedef struct product Product;

Product *Product_create(const char *name, const char *description, double price);
void Product_destroy(Product *product);

void Product_setId(Product *product, const int id);
void Product_setName(Product *product, const char *name);
void Product_setDescription(Product *product, const char *description);
void Product_setPrice(Product *product, const double price);

int Product_getId(const Product *product);
char *Product_getName(const Product *product);
char *Product_getDescription(const Product *product);
double Product_getPrice(const Product *product);

#endif /* PRODUCT_H_ */
