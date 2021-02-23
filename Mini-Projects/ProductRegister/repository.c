#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>

static List *list;

void Repository_init(void)
{
    list = List_create();
    if(list == NULL)
        abort();
}

void Repository_createRegistry(Product *product)
{
    printf("Create a new Registry.\n");
    List_add(list, product);
}

void Repository_updateRegistry(void)
{
    printf("Update a Registry.\n");
}

void Repository_searchRegistry(void)
{
    printf("Search a Registry.\n");
}

void Repository_deleteRegistry(int id)
{
    printf("\nDelete a Registry.\n\n");
    if(List_remove(list, id))
    {
        printf("ID does not exist.\n");
    }
}

void Repository_showAllRegistries(void)
{
    printf("\nShow all registries.\n\n");
    if(List_showAll(list, NULL))
    {
        printf("There is no registry.\n");
    }
}

void Repository_saveAllRegistriesInFile(void)
{
    FILE *file;
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    printf("Save Registries in a file.\n");    
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"%Y%m%d%H%M%S.txt",timeinfo);

    file = fopen(buffer, "w");
    if(List_showAll(list, file))
    {
        printf("There is no registry.\n");
    }
    fclose(file);
}