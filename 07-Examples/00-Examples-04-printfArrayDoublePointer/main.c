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

int getNumbers(char **valores);
void print(char **valores, int size);

int main(void) {

	char **valores = (char **)malloc(sizeof(char *));
	int size;

	size = getNumbers(valores);
	print(valores, size);



	return EXIT_SUCCESS;
}

int getNumbers(char **valores)
{

	*valores = (char *)malloc(5);
	for(int i = 0; i < 5; i+=1)
	{
		(*valores)[i] = i ;
	}

	return 5;
}

void print(char **valores, int size)
{
	for(int i = 0; i < size ; i++)
	{
		printf("%d ", (*valores)[i]);
	}
	putchar('\n');
}
