#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <protocol.h>
#include <string.h>

#define PORT 8080
#define MAXLINE 1024


int main()
{
  int sockfd;
  protocol_t prot;

  char buffer[MAXLINE];
  char *hello = "Hello from Client";

  struct sockaddr_in servaddr;

  //Creating a socket file descriptor 
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd < 0){
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));

  //Filling server information 
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr = INADDR_ANY;

  int n, len;

  prot.type = TYPE_DATA;
  prot.module = MODULE_2;
  strcpy(prot.payload, "0123456789ABCDEFGHIJKLMNOPQRSTUVXZ"); 
  prot.size = strlen(prot.payload);
  prot.checksum = 0xFFFF;

  len = sizeof(servaddr);
  sendto(sockfd, (const char *)&prot, sizeof(prot), MSG_CONFIRM, (const struct sockaddr *)&servaddr, len);
  printf("Hello message sent.\n");

  n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);
  buffer[n] = '\0';

  printf("Server : %s\n", buffer);
  close(sockfd);

  return EXIT_SUCCESS;
}
