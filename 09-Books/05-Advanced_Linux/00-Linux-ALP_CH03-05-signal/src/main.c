/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;

void handler(int signal_number)
{
	++sigusr1_count;
}

int main(void) {
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &handler;
	sigaction(SIGUSR1, &sa, NULL);

	printf("SIGUSR1 was raised %d times\n", sigusr1_count);
	return EXIT_SUCCESS;
}
