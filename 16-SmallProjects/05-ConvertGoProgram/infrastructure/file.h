#ifndef FILE_H_
#define FILE_H_

#include "type.h"
#include <stdio.h>

EndpointReply *File_getPageFromFile(const char *pathFile);
long File_getFileSize(FILE *file);
long File_getAllPartialsSize(EndpointReply *endpoint);

#endif /* FILE_H_ */
