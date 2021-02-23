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
#include <string.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


void timer_handler(int signum)
{
	static int count = 0;
	printf("Timer expired %d times\n", ++count);
}

int main(void) {
	struct sigaction sa;
	struct itimerval timer;

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &timer_handler;
	sigaction(SIGVTALRM, &sa, NULL);

	/* Configure to expire after 200msec */
	timer.it_value.tv_sec = 0;
	timer.it_value.tv_usec = 250000;

	/* Every 200ms */
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 250000;

	/* Register timer */
	setitimer(ITIMER_REAL, &timer, NULL);

	while(1)
	{
//		printf("Waiting handler\n");
//		sleep(1);
	}

	printf("Job is done!\n");

	return EXIT_SUCCESS;
}
