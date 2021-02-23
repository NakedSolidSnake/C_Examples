// #define __USE_MISC

#define _GNU_SOURCE

#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), sendto(), and recvfrom() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXRECVSTRING 255 /* Longest string to receive */

int main(int argc, char *argv[])
{

    /* External error handling function */
    int id;
    int sock;                           /* Socket */
    struct sockaddr_in multicastAddr;   /* Multicast Address */
    char *multicastIP;                  /* IP Multicast Address */
    unsigned int multicastPort;         /* Port */
    char recvString[MAXRECVSTRING + 1]; /* Buffer for received string */
    int recvStringLen;                  /* Length of received string */
    struct ip_mreq multicastRequest;    /* Multicast address join structure */
    if (argc != 4)                      /* Test for correct number of arguments */
    {
        fprintf(stderr, "Usage: %s <Multicast IP> <Multicast Port>In", argv[0]);
        exit(1);
    }
    multicastIP = argv[1];         /* First arg' multicast IP address (dotted quad) */
    multicastPort = atoi(argv[2]); /* Second arg' multicast port */
    id = atoi(argv[3]);
    /* Create a best-effort datagram socket using UDP */
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        fprintf(stderr, " socket () failed");
        exit(1);
    }
    /* Construct bind structure */
    memset(&multicastAddr, 0, sizeof(multicastAddr));
    multicastAddr.sin_family = AF_INET;
    multicastAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    multicastAddr.sin_port = htons(multicastPort);
    /* Zero out structure */
    /* Internet address family */
    /* Any incoming interface */
    /* Multicast port */
    /*  Bind to  the  multicast port */

    int yes = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (void *)&yes, sizeof(yes)) < 0)
    {
        fprintf(stderr, "setsockopt() failed.\n");
    }


    if (bind(sock, (struct sockaddr *)&multicastAddr, sizeof(multicastAddr)) < 0)
    {
        fprintf(stderr, "bind()  failed");
        exit(1);
    }
    /* Specify the multicast group */
    multicastRequest.imr_multiaddr.s_addr = inet_addr(multicastIP);
    /* Accept multicast from any interface */
    multicastRequest.imr_interface.s_addr = htonl(INADDR_ANY);
    /* Join the multicast group */
    if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&multicastRequest,
                   sizeof(multicastRequest)) < 0)
    {
        fprintf(stderr, "setsockopt() failed");
        exit(1);
    }
    /* Receive a single datagram from the server */    
    int _id;
    char *message;
    int ssRet;
    while (1)
    {
        memset(recvString, 0, sizeof(recvString));
        if ((recvStringLen = recvfrom(sock, recvString, MAXRECVSTRING, 0, NULL, 0)) < 0)
        {
            fprintf(stderr, "recvfrom() failed");
            exit(1);
        }
        recvString[recvStringLen] = '\0';
        ssRet = sscanf(recvString, "%d %s", &_id, message);
        if(_id == id)
            printf("I'am client %d and I read %d, I've Received' %s\n", id, ssRet, message); /* Print the  received string */

    }

    close(sock);
    exit(0);
}