#include "include/serial.h"
#include<stdio.h>
#include <string.h>
int main()
{
	const char *text = "Test\n";
	uint32_t bytes_written = 0;
	uint32_t bytes_read = 0;
	char buffer_read[10] = {0};


	Serial_Config_t serial = {
			.comport = "COM1",
			.baudrate = BAUD_115200,
			.parity = PARITY_NO,
			.stop_bits = STOPBIT_ONE
	};

	Serial_init(&serial);

	bytes_written = Serial_Write(text, (uint32_t)strlen(text));
	printf("bytes_written = %d\n", bytes_written);

	bytes_read = Serial_Read(buffer_read, sizeof(buffer_read));
	printf("bytes_read = %d\n", bytes_read);

	Serial_Close(serial.comport);

  return 0;
}
