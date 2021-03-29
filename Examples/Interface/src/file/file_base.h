#ifndef FILE_H_
#define FILE_H_

#include <stdbool.h>

bool File_init(void *args);
bool File_open(void *args);
bool File_set(void *args);
bool File_get(void *args);
bool File_close(void *args);



#endif /* FILE_H_ */
