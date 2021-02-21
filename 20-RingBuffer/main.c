/*
 * main.c
 *
 *  Created on: 17/10/2018
 *      Author: csouza
 */
#include <stdio.h>
#include <string.h>
#include "circular_buffer.h"
#include <stdlib.h>
#include <stdint.h>

#define MESSAGE_MAX_LEN 100
#define TEXTS_LEN 10

const char *texts[TEXTS_LEN] = {
		"Cristiano Silva de Souza",
		"We can do it",
		"No one is important than the world itself",
		"I read everyday but i can't remember everything",
		"I'm studing all the time but sometimes isn't quite enough",
		"today is the first at the new job",
		"I'm looking for to get more techquinic",
		"I wasn't sure about what destiny i could follow in that time",
		"For God Sake",
		"Here is the best place i ever had"
};

int main(int argc, char **argv) {
	char message_send[MESSAGE_MAX_LEN];
	char message_recv[MESSAGE_MAX_LEN];
	uint8_t rand_value = 0;

	memset(message_send, '0', sizeof(message_send));
	memset(message_recv, '0', sizeof(message_recv));

	srand(1024);


	char recv = 0;

	CIRCULAR_BUFFER_DECLARE(circ_buffer);

	while(1){
		rand_value = rand() % TEXTS_LEN;
		buffer_insert(&circ_buffer, (void *)texts[rand_value], strlen(texts[rand_value]));

		while(!buffer_empty(&circ_buffer)){
			buffer_retrieve(&circ_buffer, (void *)&recv, 1);
			printf("%c", recv);
		}
		putchar('\n');
	}
	return 0;
}


