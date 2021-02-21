#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT  8080
#define MAXLINE 1024

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

  printf("Client : %s\n", buffer);
  sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
  printf("Hello Message sent.\n");
     
  close(sockfd);
  return EXIT_SUCCESS;
}
