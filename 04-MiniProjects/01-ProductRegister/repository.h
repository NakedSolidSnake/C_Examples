#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include "product.h"

void Repository_init(void);
void Repository_createRegistry(Product *product);
void Repository_updateRegistry(void);
void Repository_searchRegistry(void);
void Repository_deleteRegistry(int id);
void Repository_showAllRegistries(void);
void Repository_saveAllRegistriesInFile(void);

#endif /* REPOSITORY_H_ */
