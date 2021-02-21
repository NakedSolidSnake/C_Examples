#include "soccer.h"
#include <stdio.h>

void Soccer_initialize(void *context)
{
    fprintf(stdout, "Soccer initialized\n");
}

void Soccer_startPlay(void *context)
{
    fprintf(stdout, "Kick off\n");
}

void Soccer_endPlay(void *context)
{
    fprintf(stdout, "End of Match\n");
}