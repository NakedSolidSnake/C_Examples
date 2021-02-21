#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <protocol.h>

#define PORT  8080
#define MAXLINE 1024

static int handle_prot(const char *buff, int size);

int main()
{
  int sockfd;
  char buffer[MAXLINE];
  char *hello = "Hello from server";
  struct sockaddr_in servaddr, cliaddr;

  //Creating a socket file descriptor
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd < 0){
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  memset(&cliaddr, 0, sizeof(cliaddr));

  //Filling server information
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);

  //Bind the socket with server address
  int ret = bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
  if(ret < 0){
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  printf("MSG_WAITALL: %d\n",MSG_WAITALL );

  int len, n;


  len = sizeof(cliaddr);
  n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
  buffer[n] = '\0';
  handle_prot(buffer, MAXLINE);

  close(sockfd);
  return EXIT_SUCCESS;
}

static void print_payload(const char *payload, int size)
{
  for(int i = 0; i < size; i++)
  {
    printf("%02X ", *(payload + i));
  }
  printf("\n");
}

static int handle_prot(const char *buff, int size)
{
  protocol_t prot;
  memset(&prot, 0, sizeof(prot));
  memcpy(&prot, buff, sizeof(prot));

  printf("TYPE: %d\n", prot.type);
  printf("CHECKSUM: %04X\n", prot.checksum);
  printf("MODULE: %d\n", prot.module);
  printf("SIZE: %d\n", prot.size);
  print_payload(prot.payload, prot.size);
  
}
