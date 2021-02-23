/*
 * protocol.c
 *
 *  Created on: 18/10/2018
 *      Author: csouza
 */

#include "../include/protocol.h"
#include <string.h>

#define STX 0x02
#define ETX 0x03

static Protocol_Functions_t f = {
//		.Init  = NULL,
		.Write = NULL,
		.Read  = NULL,
		.Close = NULL
};

typedef enum ProtocolState{
    PROTOCOL_GET_STX,
    PROTOCOL_GET_COMMAND_P1,
    PROTOCOL_GET_COMMAND_P2,
    PROTOCOL_GET_PAYLOAD_P1,
    PROTOCOL_GET_PAYLOAD_P2,
    PROTOCOL_GET_PAYLOAD_P3,
    PROTOCOL_GET_PAYLOAD_P4,
    PROTOCOL_GET_ETX,
}ProtocolState;

static ProtocolState smProtocol = PROTOCOL_GET_STX;
static int control = 0;

static unsigned char buffer[10] = {0};

int Protocol_Init(Protocol_Functions_t *functions){
//	f.Init = functions->Init;
	f.Read = functions->Read;
	f.Write = functions->Write;
	f.Close = functions->Close;
	return 0;
}

int Protocol_Get(unsigned char *protocolBuffer, int * size, unsigned long timeout)
{
    int ret = 1;
    unsigned char getChar;
    f.Read((char *)&getChar, 1);
    switch(smProtocol)
    {

    case PROTOCOL_GET_STX:
        if(getChar == STX){
            smProtocol = PROTOCOL_GET_COMMAND_P1;
        }
        control = -1;
        break;

    case PROTOCOL_GET_COMMAND_P1:
        buffer[control++] = getChar;
        smProtocol = PROTOCOL_GET_COMMAND_P2;
        break;

    case PROTOCOL_GET_COMMAND_P2:
        buffer[control++] = getChar;
        smProtocol = PROTOCOL_GET_PAYLOAD_P1;
        break;

    case PROTOCOL_GET_PAYLOAD_P1:
        buffer[control++] = getChar;
        smProtocol = PROTOCOL_GET_PAYLOAD_P2;
        break;

    case PROTOCOL_GET_PAYLOAD_P2:
        buffer[control++] = getChar;
        smProtocol = PROTOCOL_GET_PAYLOAD_P3;
        break;

    case PROTOCOL_GET_PAYLOAD_P3:
        buffer[control++] = getChar;
        smProtocol = PROTOCOL_GET_PAYLOAD_P4;
        break;

    case PROTOCOL_GET_PAYLOAD_P4:
        buffer[control] = getChar;
        smProtocol = PROTOCOL_GET_ETX;
        break;

    case PROTOCOL_GET_ETX:
        if(getChar == ETX){
            smProtocol = PROTOCOL_GET_STX;
        }
        ret = 0;
        break;

    default:
        smProtocol = PROTOCOL_GET_STX;
        break;
    }

    if(ret == 0)
    {
        memcpy(protocolBuffer, buffer, control);
        *size = control;
        memset(buffer, 0, sizeof(buffer));
        control = 0;

    }
    return 1;
}
