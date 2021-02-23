#ifndef __PROTOCOL_H
#define __PROTOCOL_H


typedef enum 
{
    DATA_Insert = 0,
    DATA_Update,
    DATA_Delete,
    DATA_Select
}eDataType_t;

typedef struct 
{
    int id;
    int size;
    char *payload;
    int checksum;
}protocol_t;

#endif 