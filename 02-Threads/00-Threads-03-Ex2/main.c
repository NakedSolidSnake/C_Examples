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
#include <pthread.h>
#include <math.h>

void *computes_square_root(void *args)
{
	int until = *((int *)args);
	float *buffer = (float *)malloc(sizeof(float) * until);
	if(buffer == NULL)
		return NULL;

	for(int i = 0; i <= until; i++)
	{
		buffer[i] = powf(i, 2.0);
	}

	return (void *)buffer;
}

int main(void) {

	void *getData = NULL;
	int num = 99;
	pthread_t thread;

	pthread_create(&thread, NULL, computes_square_root, (void *)&num);

	printf("Waiting data processing...\n");
	pthread_join(thread, &getData);
	if(getData != NULL)
	{
		//process
		float *values = (float *)getData;
		for(int i = 0; i < num; i++)
		{
			printf("%d square %.0f\n", i, values[i]);
		}

		free(getData);
	}

	return EXIT_SUCCESS;
}

