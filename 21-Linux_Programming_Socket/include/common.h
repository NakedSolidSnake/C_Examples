#ifndef __COMMON_H
#define __COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define ERROR       -1
#define MAX_BUF      1024

void print_error(const char *error_message, ...);

#endif