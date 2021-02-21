#ifndef __PROTOCOL_H
#define __PROTOCOL_H

#define TYPE_COMMAND  1
#define TYPE_DATA     2

#define MODULE_1      1 
#define MODULE_2      2

/* +------+--------+------+---------+------+
 * | TYPE | MODULE | SIZE | PAYLOAD | CHCK | 
 * +------+--------+------+---------+------+
 *  4Bytes  4Bytes  4bytes 1024bytes  4bytes
 */

typedef struct protocol
{
  int type;
  int module;
  int size;
  char payload[1024];
  int checksum;
}protocol_t;

#endif
