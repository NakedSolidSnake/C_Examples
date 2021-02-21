#include "aux.h"

int compare(struct timespec *start, struct timespec *end, struct timespec *offset)
{
    if(!start || !end || !offset)
        return -1;
    double _start = (double)start->tv_sec + (double)start->tv_nsec/(double)1000000000;
    double _end = (double)end->tv_sec  + (double)end->tv_nsec /(double)1000000000;
    double _offset = (double)offset->tv_sec  + (double)offset->tv_nsec /(double)1000000000;

    return ((_start + _offset) > _end);
}

int process_activate(const char *process_name)
{   
    return 0;
}