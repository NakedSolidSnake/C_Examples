#ifndef __DATA_H
#define __DATA_H

#define MAX_LEN_DATA            100

typedef struct data_t
{
   long id;
   char b_data[MAX_LEN_DATA];
}data_t;


int data_init(data_t *d);

#endif
