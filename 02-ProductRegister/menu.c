#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "repository.h"

IMENU imenu[] = 
{
    MENU_createRegistry,
    MENU_updateRegistry,
    MENU_searchRegistry,
    MENU_deleteRegistry,
    MENU_showAllRegistries,
    MENU_saveAllRegistriesInFile,
    MENU_exit
};

int MENU_getSelection(const char **options, int items_amount)
{
    int selection;
    for(int i = 0; i < items_amount; i++)
    {
        printf("%s\n", options[i]);
    }

    while(1)
    {
        printf("Select an option: ");
        selection = fgetc(stdin) - '0';
        getchar();
        if(selection >= 0 && selection < items_amount)
            break;
        printf("Incorrect option. Select a valid option.\n");
    }

    return selection;
}

void MENU_createRegistry(void)
{
    char name[NAME_LEN];
    char description[DESCRIPTION_LEN];
    double price;
    
    printf("Enter the name: ");
    fgets(name, NAME_LEN, stdin);
    name[strlen(name) - 1] = 0;

    printf("Enter the description: ");
    fgets(description, DESCRIPTION_LEN, stdin);
    description[strlen(description) - 1] = 0;

    printf("Enter the product price: ");
    scanf("%lf", &price);
    getchar();

    Product *product = Product_create(name, description, price);
    Repository_createRegistry(product);
}

void MENU_updateRegistry(void)
{
    Repository_updateRegistry();
}

void MENU_searchRegistry(void)
{
    Repository_searchRegistry();
}

void MENU_deleteRegistry(void)
{
    int id;
    printf("Type the ID to delete: ");
    scanf("%d", &id);
    getchar();

    Repository_deleteRegistry(id);
}

void MENU_showAllRegistries(void)
{
    Repository_showAllRegistries();
}

void MENU_saveAllRegistriesInFile(void)
{
    Repository_saveAllRegistriesInFile();
}

void MENU_exit(void)
{
    printf("Exiting application...\n");
    exit(0);
}