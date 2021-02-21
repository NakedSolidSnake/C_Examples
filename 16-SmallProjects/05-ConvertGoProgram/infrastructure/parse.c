#include "parse.h"
#include <stdlib.h>
#include <string.h>

char *Parse_getService(char *buffer)
{   
    char *pch = NULL;
    char *end = NULL;
    char *pBuffer = buffer;
    pch=strchr(buffer, '/');

    for(int i = 0; ; i++)
    {
        if(!pch)
            return NULL;

        if(*(pch + i) == '?' || *(pch + i) == ' ')
        {
            end = (pch + i);
            break;
        }
    }

    return strndup(pch, end - pch);
}

char *Parse_getParameters(char *buffer)
{   
    char *found =  strstr(buffer, "\r\n\r\n");    
    if(found)
    {
        found = found + strlen("\r\n\r\n");
    }
    return found;
}