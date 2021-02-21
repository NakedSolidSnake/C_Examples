#include "template.h"
#include <stdlib.h>
#include <stdio.h>

static ITemplate object;

static int verifyFunctions(ITemplate *object);

void concreteOpen(Concrete *context)
{
    ITemplate *base = (ITemplate *)context;

    object.initialize = base->initialize;
    object.start = base->start;
    object.end = base->end;
}

void run(void)
{
    if(verifyFunctions(&object))
        return ;

    object.initialize(&object);
    object.start(&object);
    object.end(&object);
}

static int verifyFunctions(ITemplate *object)
{
    if(!object){
        fprintf(stderr, "game parameter is null.\n");
        return EXIT_FAILURE;
    }

    if(!object->initialize){
        fprintf(stderr, "game initializer parameter is null.\n");
        return EXIT_FAILURE;
    }

    if(!object->start){
        fprintf(stderr, "game start parameter is null.\n");
        return EXIT_FAILURE;
    }

    if(!object->end){
        fprintf(stderr, "game end parameter is null.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}