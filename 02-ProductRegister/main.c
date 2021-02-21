#include "menu.h"
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "repository.h"

extern IMENU imenu[];

const char *options[] = 
{
    "[0] - Create a new registry",
    "[1] - Update a registry",
    "[2] - Search a registries",
    "[3] - Delete a registry",
    "[4] - List all registries",
    "[5] - Export registries in a file",
    "[6] - Exit application"
};

const int options_amount = sizeof(options)/sizeof(options[0]);

int main(void)
{
    int selection;
    Repository_init();
    while(1)
    {
        selection = MENU_getSelection(options, options_amount);
        printf("\n");
        imenu[selection]();
        printf("\n");
    }

    return EXIT_SUCCESS;
}