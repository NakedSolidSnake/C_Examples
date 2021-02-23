#include <wine.h>
#include <stdio.h>
#include <string.h>


char *showWine(const Wine *wine)
{
    char message[1024] = {0};
    snprintf(message, 1024, "Wine: %s, Type: %s, Price: %0.2lf, Harvest: %d", wine->name,
                                                                              wine->type,
                                                                              wine->price,
                                                                              wine->harvest);

    return strndup(message, strlen(message) + 1);
    
}

bool verifyPrice(double price)
{
    bool isPriceLow = false;
    if( price < 25.0 )
    {
        isPriceLow = true;
    }
        
    return isPriceLow;
}