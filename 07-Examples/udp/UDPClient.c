#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024


int main()
{
  int sockfd;

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

  len = sizeof(servaddr);
  sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *)&servaddr, len);
  printf("Hello message sent.\n");

  n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);
  buffer[n] = '\0';

  printf("Server : %s\n", buffer);
  close(sockfd);

  return EXIT_SUCCESS;
}
