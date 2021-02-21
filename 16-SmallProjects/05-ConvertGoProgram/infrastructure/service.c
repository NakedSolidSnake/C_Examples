#include "service.h"

int RouteRegistry(Routes *routes, Route *route)
{
    int ret = -1;
    if(routes->route_amount < ROUTES_AMOUNT)
    {
        routes->routes[routes->route_amount].name = route->name;
        routes->routes[routes->route_amount].handle = route->handle;
        routes->route_amount++;        
        ret = 0;
    }

    return ret;
}
