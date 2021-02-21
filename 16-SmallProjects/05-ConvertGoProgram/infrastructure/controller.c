#include "controller.h"
#include <service.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <file.h>
#include "Repository.h"
#include "handle_partials.h"

static EndpointReply *Index(const char *data);
static EndpointReply *New(const char *data);
static EndpointReply *Insert(const char *data);
static EndpointReply *Delete(const char *data);
static EndpointReply *Edit(const char *data);
static EndpointReply *Update(const char *data);

const Route routes[] = 
{
    {"/"      , Index },
    {"/new"   , New   },
    {"/insert", Insert},
    {"/delete", Delete},
    {"/edit"  , Edit  },
    {"/update", Update},
};

const int route_amount = sizeof(routes) / sizeof(routes[0]);

static Routes route;

static EndpointReply *Index(const char *data)
{
    printf("Index.\n");
    (void)data;
    EndpointReply *_data = File_getPageFromFile("../templates/index.html");
    Product *product;
    Repository_GetAllProducts(&product);

    Repository_Free(&product);
    return _data;
}

static EndpointReply *New(const char *data)
{
    printf("New.\n");
    EndpointReply *_data = File_getPageFromFile("../templates/new.html");
    return _data;
}

static EndpointReply *Insert(const char *data)
{
    int ret = 0;
    printf("Insert.\n");
    char *pData = data;
    while(*pData)
    {
        if(*pData == '&')
            *pData = ' ';
        pData++;
    }
    //nome=Cristiano+Silva+de+Souza&descricao=This+is+a+description&preco=565&quantidade=15&quantidade=1
    Product product;
    
    ret = sscanf(data, "nome=%s descricao=%s preco=%lf quantidade=%d", product.name, product.description, &product.price, &product.quantity);
    if(ret == 4)
    {
        //remove + signal from strings
        pData = product.name;
        while(*pData)
        {
            if(*pData == '+')
                *pData = ' ';
            pData++;
        }

        pData = product.description;
        while(*pData)
        {
            if(*pData == '+')
                *pData = ' ';
            pData++;
        }
    }

    Repository_InsertProduct(&product);
    return Index(NULL);
}

static EndpointReply *Delete(const char *data)
{
    printf("Delete.\n");
    return NULL;
}

static EndpointReply *Edit(const char *data)
{
    printf("Edit.\n");
    EndpointReply *_data = File_getPageFromFile("../templates/edit.html");
    return _data;
}

static EndpointReply *Update(const char *data)
{
    printf("Update.\n");
    return NULL;
}

void Controller_LoadRoutes(void)
{    
    for(int i = 0; i < route_amount; i++)
    {
        RouteRegistry(&route, &routes[i]);
    }
}

EndpointReply *Controller_execute(const char *service, const char *endpoint, const char *vars)
{
    for(int i = 0; i < route_amount; i++)
    {
        if(strcmp(routes[i].name, service) == 0)
        {
            EndpointReply *data = routes[i].handle(vars);
            return data;
        }
    }

    return NULL;
}

void Controller_Free(EndpointReply *endpointReply)
{
    if(endpointReply)
    {
        if(endpointReply->partials.head)
        {
            Partials_freeHead(endpointReply->partials.head);
        }

        if(endpointReply->partials.menu)
        {
            Partials_freeMenu(endpointReply->partials.menu);
        }

        if(endpointReply->partials.page)
        {
            Partials_freePage(endpointReply->partials.page);
        }

        if(endpointReply->partials.footer)
        {
            Partials_freeFooter(endpointReply->partials.footer);
        }
        free(endpointReply);
    }
}