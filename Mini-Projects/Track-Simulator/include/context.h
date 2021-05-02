#ifndef CONTEXT_H
#define CONTEXT_H

#include <airspace.h>
#include <volume.h>
#include <track.h>
#include <stdbool.h>

typedef struct 
{
    Airspace airspace;
    Volume volume;
    Track track;
    bool is_inside_airspace;
    bool is_a_colision;
} Context;

#endif /* CONTEXT_H */
