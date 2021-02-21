#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
  int x;
  struct sockaddr_in adr_inet;
  const char *addr[] = {
    "44.135.86.12",
    "127.0.0.1",
    "172.16.23.95",
    "192.168.9.1"
  };

  unsigned long net, hst;
  for(x = 0; x < 4; ++x){
    memset(&adr_inet, 0, sizeof(adr_inet));
    adr_inet.sin_family = AF_INET;
    adr_inet.sin_port = htons(9000);
    if( !inet_aton(addr[x], &adr_inet.sin_addr))
      puts("bad address");

    hst = inet_lnaof(adr_inet.sin_addr);
    net = inet_netof(adr_inet.sin_addr);

    printf("%14s : net=0x%08lX host=0x%08lX\n", inet_ntoa(adr_inet.sin_addr), net, hst);

    memset(&adr_inet, 0, sizeof(adr_inet));
    adr_inet.sin_family = AF_INET;
    adr_inet.sin_port = htons(9000);

    adr_inet.sin_addr = inet_makeaddr(net, hst);

    printf("%14s : %s\n\n", "inet_makeaddr", inet_ntoa(adr_inet.sin_addr));
  }
}
