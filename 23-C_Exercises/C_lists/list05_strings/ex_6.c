#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char nome[100];
    char sexo;
    int idade;

    printf("Entre com o nome.:");
    fgets(nome, 100 - 1, stdin);
    nome[strlen(nome) - 1] = 0;

    printf("Entre com o Sexo.:");
    sexo = getchar();

    printf("Entre com a idade.:");
    scanf("%d", &idade);

    if(idade < 25 && sexo == 'f')
        printf("%s ACEITA.\n", nome);
    else
        printf("NÃO ACEITA.\n");
    return EXIT_SUCCESS;
}