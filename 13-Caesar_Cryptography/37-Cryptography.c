/*
 ============================================================================
 Name        : 37-Cryptography.c
 Author      : Cristiano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, x;
	char str[100];

	puts("\nEnter a string: ");
	gets(str);

	puts("Choose some options.:");
	puts("1-Encrypt");
	puts("2-Decrypt");
	scanf("%d", &x);

	switch(x)
	{
	case 1:
		for(i = 0 ; (i < 100 && str[i] != '\0'); i++)
		{
			str[i] = str[i] + 3;
		}
		printf("Encrypted: %s\n", str);
		break;

	case 2:
		for(i = 0 ; (i < 100 && str[i] != '\0'); i++)
		{
			str[i] = str[i] - 3;
		}
		printf("Encrypted: %s\n", str);
		break;

	default:
		puts("Error");
	}

	return EXIT_SUCCESS;
}
