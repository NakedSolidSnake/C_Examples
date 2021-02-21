#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>

#define MAX 4096
#define PORT 1234
#define SA struct sockaddr

#define ROVER_SERVER "ROVER_SERVER"

#define RUNNING 1
#define STOPPED 0

static int server_running = RUNNING;

typedef enum COMM_ERROR
{
  ERROR_RECV = -1,
  ERROR_CLIENT_DISCONNECTED = 0
} COMM_ERROR;

void readBuffer(int sockfd, char *buff, int size);
int checkMethod(char *buff, int size);


// Function designed for chat between client and server.
void func(int sockfd)
{  
  char buff[MAX];
  int ret;
  // infinite loop for chat

//   while (server_running)
//   {
    bzero(buff, MAX);

    // read the message from client and copy it in buffer
    ret = recv(sockfd, buff, sizeof(buff), 0);

    switch (ret)
    {

    case ERROR_RECV:      
      close(sockfd);
      return;

    case ERROR_CLIENT_DISCONNECTED:     
      close(sockfd);
      return;    

      default:
        printf("received: %s\n", buff);
        readBuffer(sockfd, buff, ret);
    }
//   }
  close(sockfd);
}

int main()
{
  int sockfd, connfd, len, yes = 1;
  struct sockaddr_in servaddr, cli;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)  
    exit(1);
  
  
  bzero(&servaddr, sizeof(servaddr));

  // assign IP, PORT
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
      //log error 
      return 1;
    }


  // Binding newly created socket to given IP and verification
  if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)   
    exit(1);  
  

  while (server_running)
  {    
    if ((listen(sockfd, 1)) != 0)    
      exit(1);
    
    
    len = sizeof(cli);    
    connfd = accept(sockfd, (SA *)&cli, &len);
    if (connfd < 0)    
      exit(1);
        
    func(connfd);
  }
  
  close(sockfd);
}

void readBuffer(int sockfd, char *buff, int size)
{
    char *pch = strtok (buff," ");
    char *message = NULL;
	// while (pch != NULL)
	// {
	// 	printf ("%s\n",pch);
	// 	pch = strtok (NULL, " ,.-");
	// }

    if(!checkMethod(pch, size)){
        // message = "HTTP/1.1 200 OK\n\r\n\r";
        // message = "HTTP/1.1 200 OK\r\nCache-Control : no-cache, private\r\nContent-Length : 107\r\nDate : Mon, 24 Nov 2014 10:21:21 GMT\r\n\r\n";
        // message = "HTTP/1.1 200 OK\r\nCache-Control: no-cache, private\r\nContent-Length: 107\r\nDate: Mon, 14 Nov 2020 21:46:38 GMT\r\n\r\n";
        message = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 6\n\n200 OK";
    }else{
         message = "HTTP/1.1 404 Not Found\n\r\n\r";
    }

    send(sockfd, message, strlen(message), 0);
}

int checkMethod(char *buff, int size)
{
    const char *method[] = {
        "GET",
        "POST",
        "PUT",
        "DELETE"
    };

    

    for(int i = 0; i < 4; i++)
    {
        if(!strncmp(method[i], buff, strlen(method[i]))){
            printf("OK\n");            
            return 0;
        }
    }

    return 1;
}