/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct char_print_parms
{
	char character;
	int count;
};

void *char_print(void *args)
{
	struct char_print_parms *p = (struct char_print_parms *)args;
	int i;

	for(i = 0; i < p->count; i++)
		fputc(p->character, stderr);
	return NULL;
}

int main(void) {
	pthread_t thread1_id;
	pthread_t thread2_id;

	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;

	thread1_args.character = 'x';
	thread1_args.count = 30000;
	pthread_create(&thread1_id, NULL, &char_print, &thread1_args);

	thread1_args.character = 'o';
	thread1_args.count = 20000;
	pthread_create(&thread2_id, NULL, &char_print, &thread2_args);

	pthread_join(thread1_id, NULL);
	pthread_join(thread2_id, NULL);

	return EXIT_SUCCESS;
}
