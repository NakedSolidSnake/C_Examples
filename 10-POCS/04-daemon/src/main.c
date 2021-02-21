#include <server/server_tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int receive(char *buffer, int size);
static int send(char *buffer, int *size);

int main()
{

  Server_t s = {
    .socket = -1,
    .port = "8085",
    .cb.recv = receive,
    .cb.send = send
  };

  Server_init(&s);
  Server_exec(&s);
}

static int receive(char *buffer, int size)
{
  buffer[size] = '\0';

  for(int i = 0; i < size; i++){
      buffer[i] = toupper(buffer[i]);
  }

  return 0;
}


static int send(char *buffer, int *size)
{
    
}