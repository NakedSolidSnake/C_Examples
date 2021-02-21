#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
  struct sockaddr_in adr_inet;
  int len_inet;

  memset(&adr_inet, 0, sizeof(adr_inet));

  adr_inet.sin_family = AF_INET;
  adr_inet.sin_port = htons(9000);

  if(!inet_aton("127.0.0.23", &adr_inet.sin_addr))
    puts("bad address");

  len_inet = sizeof(adr_inet);

  printf("The IP Adress is %s\n", inet_ntoa(adr_inet.sin_addr));

  return 0;
}
