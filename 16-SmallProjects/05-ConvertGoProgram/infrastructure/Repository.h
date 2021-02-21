#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include "type.h"

void Repository_GetAllProducts(Product **products);
void Repository_Free(Product **products);
void Repository_InsertProduct(Product *product);
void Repository_DeleteProduct(int id);
Product Repository_EditProduct(int id);
void Repository_UpdateProduct(Product *product);


#endif /* REPOSITORY_H_ */
