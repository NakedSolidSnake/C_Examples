/*
 * serial.c
 *
 *  Created on: 16/10/2018
 *      Author: csouza
 */

#include "../include/serial.h"
#include <windows.h>
#include <stdlib.h>		//atoi()
#include <stdio.h>

#define BAUDRATE_AMOUNT 15
#define DATA_BIT_LEN 8

static HANDLE hComm = -1;

const uint32_t baudrate_table[BAUDRATE_AMOUNT] = {
		110,
		300,
		600,
		1200,
		2400,
		4800,
		9600,
		14400,
		19200,
		38400,
		56000,
		57600,
		115200,
		128000,
		256000,
};

//uint8_t Serial_init(const char * comport, BAUDRATE_t baudrate, STOP_BITS_t stop_bits, PARITY_t parity)
uint8_t Serial_init(Serial_Config_t *serial_config)
{
	uint8_t comport_number;
	volatile char debug = 0;
	if(!serial_config){
		return 1; //error invalid parameter
	}

	debug = serial_config->comport[3];
	comport_number = (uint8_t)atoi((const char *)&serial_config->comport[3]);

	if(comport_number < 0 || comport_number > 9){
		printf("comport out of range must be 0...9\n");
		return 1; //
	}

	hComm = CreateFile(serial_config->comport,          // for COM1—COM9 only
			GENERIC_READ | GENERIC_WRITE, //Read/Write
			0,               // No Sharing
			NULL,            // No Security
			OPEN_EXISTING,   // Open existing port only
			0,               // Non Overlapped I/O
			NULL);

	if (hComm == INVALID_HANDLE_VALUE){

		printf("Error in opening serial port");
		return 1;
	}
	else
		printf("opening serial port successful");

	DCB dcbSerialParams = { 0 }; // Initializing DCB structure
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	dcbSerialParams.BaudRate = baudrate_table[serial_config->baudrate];
	dcbSerialParams.ByteSize = DATA_BIT_LEN;
	dcbSerialParams.StopBits = (uint8_t)serial_config->stop_bits;
	dcbSerialParams.Parity   = (uint8_t)serial_config->parity;

	SetCommState(hComm, &dcbSerialParams);

	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout         = 50; // in milliseconds
	timeouts.ReadTotalTimeoutConstant    = 50; // in milliseconds
	timeouts.ReadTotalTimeoutMultiplier  = 10; // in milliseconds
	timeouts.WriteTotalTimeoutConstant   = 50; // in milliseconds
	timeouts.WriteTotalTimeoutMultiplier = 10; // in milliseconds

	return 0;
}

uint32_t Serial_Write(const char *buffer_write, uint32_t size)
{
	uint32_t bytes_written = 0;
	if(hComm >= 0)
	{
		WriteFile(hComm,        // Handle to the Serial port
				buffer_write,     // Data to be written to the port
				size,  //No of bytes to write
				&bytes_written, //Bytes written
				NULL);
	}

	SetCommMask(hComm, EV_RXCHAR);
	DWORD dwEventMask;
	WaitCommEvent(hComm, &dwEventMask, NULL);

	return bytes_written;
}

uint32_t Serial_Read(char *buffer_read, uint32_t size)
{
	uint32_t bytes_read = 0, read = 0;
	if(hComm >= 0)
	{
		if(buffer_read && size > 0)
		{
			uint8_t resul = 0;
			do
			{
				resul = ReadFile( hComm,           //Handle of the Serial port
						&buffer_read,       //Temporary character
						1,//Size of TempChar
						&read,    //Number of bytes read
						NULL);
				if(resul)
					bytes_read++;

			}	while (--size);
		}
	}

	return bytes_read;

}

uint8_t Serial_Close(const char * comport)
{
	if(comport && hComm >= 0){
		CloseHandle(hComm);
	}
	return 0;
}
