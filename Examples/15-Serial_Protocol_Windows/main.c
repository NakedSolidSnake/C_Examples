/*
 * main.c
 *
 *  Created on: 18/10/2018
 *      Author: csouza
 */

#include <stdio.h>
#include "include/protocol.h"
#include "include/serial.h"


int main()
{
	unsigned char buffer[10];
	int size = 0;

	Serial_Config_t serial = {
			.comport = "COM1",
			.baudrate = BAUD_115200,
			.parity = PARITY_NO,
			.stop_bits = STOPBIT_ONE
	};


	Protocol_Functions_t functions = {
			.Write = Serial_Write,
			.Read = Serial_Read,
			.Close = Serial_Close
	};

	Serial_init(&serial);
	Protocol_Init(&functions);

	while(1){
		Protocol_Get(buffer, &size, 0);
		printf("%s\n", buffer);
	}

	Serial_Close("COM1");
    return 0;
}
