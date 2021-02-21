/*
 * protocol.h
 *
 *  Created on: 18/10/2018
 *      Author: csouza
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <stdint.h>

typedef void (*State)(void);

typedef struct Protocol_Functions{
//	uint8_t  (*Init)(Serial_Config_t *serial_config);
	uint32_t (*Write)(const char *buffer_write, uint32_t size);
	uint32_t (*Read)(char *buffer_read, uint32_t size);
	uint8_t  (*Close)(const char * comport);
}Protocol_Functions_t;



//void Protocol_Next_State(State state);
int Protocol_Init(Protocol_Functions_t *functions);
int Protocol_Get(unsigned char *protocolBuffer, int * size, unsigned long timeout);

#endif /* PROTOCOL_H_ */
