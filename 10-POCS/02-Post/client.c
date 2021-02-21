#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
//Create a Socket for server communication
short SocketCreate(void)
{
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}
//try to connect with server
int SocketConnect(int hSocket)
{
    int iRetval = -1;
    int ServerPort = 3404;
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //Local Host
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);
    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
    return iRetval;
}
// Send the data to the server and set the timeout of 20 seconds
int SocketSend(int hSocket, char *Rqst, short lenRqst)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; /* 20 Secs Timeout */
    tv.tv_usec = 0;
    if (setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}
//receive the data from the server
int SocketReceive(int hSocket, char *Rsp, short RvcSize)
{
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; /* 20 Secs Timeout */
    tv.tv_usec = 0;
    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    printf("Response %s\n", Rsp);
    return shortRetval;
}
//main driver program
int main(int argc, char *argv[])
{


    char aszXmlData[] = "<body><name>amlendra</name><age>25</age></body>";
    char aszXmlRequest[250] = {0};
    char aszServiceMethod[] = "applicationform.svc/getdetail";
    char aszRequest[150] = {0};
    char aszHostIp[30] = "192.168.1.6";
    char aszPort[] = "3404";
    sprintf(aszRequest, "http://%s:%s/%s/%s HTTP/1.1", aszHostIp, aszPort, aszServiceMethod);
    printf("Method and Resource path is below:\n\n\n");
    printf("%s", aszRequest);
    strcat(aszHostIp, ":");
    strcat(aszHostIp, aszPort);
    printf("\n\nHOST header is below:\n\n\n");
    printf("%s", aszHostIp);
    sprintf(aszXmlRequest, "POST %s\r\nHost: %s\r\nContent-Type: application/xml\r\nContent-Length: %d\r\n\r\n%s\r\n", aszRequest, aszHostIp, strlen(aszXmlData), aszXmlData);
    printf("\n\n\nPOST Request which send to the server:\n\n");
    printf("%s", aszXmlRequest);

    int hSocket, read_size;
    struct sockaddr_in server;
    char SendToServer[100] = {0};
    char server_reply[200] = {0};
    //Create socket
    hSocket = SocketCreate();
    if (hSocket == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }
    printf("Socket is created\n");
    //Connect to remote server
    if (SocketConnect(hSocket) < 0)
    {
        perror("connect failed.\n");
        return 1;
    }
    printf("Sucessfully conected with server\n");
    printf("Enter the Message: ");
    // gets(SendToServer);
    //Send data to the server
    SocketSend(hSocket, aszXmlRequest, strlen(aszXmlRequest));
    //Received the data from the server
    // read_size = SocketReceive(hSocket, server_reply, 200);
    // printf("Server Response : %s\n\n", server_reply);
    close(hSocket);
    shutdown(hSocket, 0);
    shutdown(hSocket, 1);
    shutdown(hSocket, 2);
    return 0;
}