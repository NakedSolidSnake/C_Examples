#include <data.h>
#include <string.h>
#include <stdlib.h>

int data_init(data_t *d)
{
  if(d == NULL)
    return -1;

  memset(d, 0, sizeof(data_t));
  return 0;
}
