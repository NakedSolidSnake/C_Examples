#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 


static void turnLeft();
static void turnRight();
static void goForward();
static void stop();
  
// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
    char buff[MAX]; 
    int n; 
    // infinite loop for chat 
    for (;;) { 
        bzero(buff, MAX); 
  
        // read the message from client and copy it in buffer 
        read(sockfd, buff, sizeof(buff)); 
  
        // if msg contains "Exit" then server exit and chat ended. 
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 

        else if(strncmp("left", buff, 4) == 0){
          turnLeft(); 
        }

        else if(strncmp("right", buff, 5) == 0){
          turnRight(); 
        }

        else if(strncmp("go", buff, 2) == 0){
          goForward(); 
        }

        else if(strncmp("stop", buff, 4) == 0){
          stop(); 
        }
        
        else if(strncmp("quit", buff, 4) == 0){
          close(sockfd);
          break;
        }
    } 
} 
  
// Driver function 
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
    while(1)
    {  
      // Now server is ready to listen and verification 
      if ((listen(sockfd, 1)) != 0) { 
          printf("Listen failed...\n"); 
          exit(0); 
      } 
      else
          printf("Server listening..\n"); 
      len = sizeof(cli); 
    
      // Accept the data packet from client and verification 
      connfd = accept(sockfd, (SA*)&cli, &len); 
      if (connfd < 0) { 
          printf("server acccept failed...\n"); 
          exit(0); 
      } 
      else
          printf("server acccept the client...\n"); 
    
      // Function for chatting between client and server 
      func(connfd); 
    }  
    // After chatting close the socket 
    close(sockfd); 
} 

static void turnLeft()
{
  printf("Turning left.\n");
}

static void turnRight()
{
  printf("Turning Right.\n");
}

static void goForward()
{
  printf("Going forward.\n");
}

static void stop()
{ 
  printf("Stop.\n");
}
  
