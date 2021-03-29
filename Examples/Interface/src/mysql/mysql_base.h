#ifndef MYSQL_BASE_H_
#define MYSQL_BASE_H_

#include <stdbool.h>

bool Database_init(void *args);
bool Database_open(void *args);
bool Database_set(void *args);
bool Database_get(void *args);
bool Database_close(void *args);

#endif /* MYSQL_BASE_H_ */
