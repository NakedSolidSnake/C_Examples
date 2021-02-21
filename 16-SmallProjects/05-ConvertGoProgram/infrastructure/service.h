#ifndef ROUTES_H_
#define ROUTES_H_

#include "type.h"

#define ROUTES_AMOUNT 10

typedef EndpointReply *(*HandleRoute)(const char *data);

typedef struct 
{
    const char *name;
    HandleRoute handle;
} Route;

typedef struct 
{
    Route routes[ROUTES_AMOUNT];
    int route_amount;
} Routes;

int RouteRegistry(Routes *routes, Route *route);

#endif /* ROUTES_H_ */
