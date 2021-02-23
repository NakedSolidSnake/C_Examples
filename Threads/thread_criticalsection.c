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
#include <string.h>

float *account_balances;

int process_transaction(int from_acct, int to_acct, float dollars)
{
	int old_cancel_state;

	if(account_balances[from_acct] < dollars)
		return 1;

	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancel_state);
	/* Critical section */
	account_balances[to_acct] += dollars;
	account_balances[from_acct] -= dollars;
	/* End */
	pthread_setcancelstate(old_cancel_state, NULL);
	return 0;
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
