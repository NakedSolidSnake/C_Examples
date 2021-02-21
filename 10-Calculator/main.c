/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

double operation(int option, double val_a, double val_b);


int main(void) {
	int action;
	double num1, num2;

	printf("****************************************\n");
	printf("*              Calculadora             *\n");
	printf("****************************************\n");

	printf("Entre dois numeros:\n");
	printf("Entre com o primeiro numero: ");
	scanf("%lf", &num1);
	printf("Entre com o segundo numero: ");
	scanf("%lf", &num2);

	printf("Escolha a operação:\n");
	printf("[1] - Soma (a + b)\n");
	printf("[2] - Subtrai (a - b)\n");
	printf("[3] - Divide (a / b)\n");
	printf("[4] - Multiplica (a * b)\n");

	printf("Entre com a operação: ");
	scanf("%d", &action);

	printf("O Resultado da operação é %f.\n", operation(action, num1, num2));


	return EXIT_SUCCESS;
}

double operation(int option, double val_a, double val_b)
{
	double result = 0.0;

	if(option == 1)
	{
		result = val_a + val_b;
	}
	else if(option == 2)
	{
		result = val_a - val_b;
	}
	else if(option == 3)
	{
		if(val_b != 0.0)
			result = val_a / val_b;
	}

	else if(option == 4)
	{
		result = val_a * val_b;
	}

	return result;
}
