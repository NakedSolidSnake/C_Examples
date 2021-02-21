#ifndef __AUX_H
#define __AUX_H

#include <sys/time.h>   
#include <sys/resource.h> 

int compare(struct timespec *start, struct timespec *end, struct timespec *offset);

int process_activate(const char *process_name);

#endif