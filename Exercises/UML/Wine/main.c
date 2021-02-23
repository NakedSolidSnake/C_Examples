#include <wine.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    cadastrar = 1,
    verificar,
    mostrar
} opcoes;

int menu(void);
int cadastrar_vinho(const Wine *wine);
int verificar_preco(const Wine *wine);
int mostrar_vinho(const Wine *wine);

int main(int argc, char *argv[])
{
    int escolha = 1;
    Wine wine  = {0};

    while (escolha != 0)
    {
        escolha = menu();

        if (escolha == cadastrar)
        {
            cadastrar_vinho(&wine);
        }
        else if (escolha == verificar)
        {
            verificar_preco(&wine);
        }
        else if (escolha == mostrar)
        {
            mostrar_vinho(&wine);
        }
    }

    printf("finalizando programa..\n");

    return 0;
}

int menu(void)
{
    int option;
    printf("[1] - Cadastrar vinho.\n");
    printf("[2] - Verificar preco.\n");
    printf("[3] - Mostrar vinho.\n");
    printf("[0] - Sair.\n");

    scanf("%d", &option);
    getchar();
    return option;
}

int cadastrar_vinho(const Wine *wine)
{
    printf("Nome do vinho: ");
    fgets(wine->name, WINE_NAME_LEN - 1, stdin);

    printf("Tipo do vinho: ");
    fgets(wine->type, WINE_TYPE_LEN - 1, stdin);

    printf("Preco do vinho: ");
    scanf("%lf", &wine->price);
    getchar();

    printf("Safra do vinho: ");
    scanf("%d", &wine->harvest);
    getchar();

    return 0;
}

int verificar_preco(const Wine *wine)
{
    if (verifyPrice(wine->price))
    {
        printf("Produto em promocao.\n");
    }

    return 0;
}

int mostrar_vinho(const Wine *wine)
{
    char *string = showWine(wine);
    printf("%s.\n", string);
    free(string);
}