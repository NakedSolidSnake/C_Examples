/*
 * serial.h
 *
 *  Created on: 16/10/2018
 *      Author: csouza
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdint.h>

typedef enum STOP_BITS{
	STOPBIT_ONE,
	STOPBIT_ONE_AND_HALF,
	STOPBIT_TWO
}STOP_BITS_t;

//typedef enum DATA_BITS{
//
//}DATA_BITS_t;

typedef enum BAUDRATE{
	BAUD_110,
	BAUD_300,
	BAUD_600,
	BAUD_1200,
	BAUD_2400,
	BAUD_4800,
	BAUD_9600,
	BAUD_14400,
	BAUD_19200,
	BAUD_38400,
	BAUD_56000,
	BAUD_57600,
	BAUD_115200,
	BAUD_128000,
	BAUD_256000
}BAUDRATE_t;

typedef enum PARITY{
	PARITY_NO,
	PARITY_ODD,
	PARITY_EVEN,
	PARITY_MARK,
	PARITY_SPACE
}PARITY_t;

typedef struct Serial_Config{
	const char * comport;
	BAUDRATE_t baudrate;
	STOP_BITS_t stop_bits;
	PARITY_t parity;
}Serial_Config_t;



//uint8_t Serial_init(const char * comport, BAUDRATE_t baudrate, STOP_BITS_t stop_bits, PARITY_t parity);
uint8_t Serial_init(Serial_Config_t *serial_config);
uint32_t Serial_Write(const char *buffer_write, uint32_t size);
uint32_t Serial_Read(char *buffer_read, uint32_t size);
uint8_t Serial_Close(const char * comport);

#endif /* SERIAL_H_ */
