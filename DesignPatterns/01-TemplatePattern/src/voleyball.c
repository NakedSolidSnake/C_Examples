#include "voleyball.h"
#include <stdio.h>

void Voleyball_initialize(void *context)
{
    fprintf(stdout, "Voleyball initialized\n");
}

void Voleyball_startPlay(void *context)
{
    fprintf(stdout, "Start match\n");
}

void Voleyball_endPlay(void *context)
{
    fprintf(stdout, "End of Match\n");
}