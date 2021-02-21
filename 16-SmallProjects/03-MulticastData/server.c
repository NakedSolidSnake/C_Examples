#include <stdio.h>      /* for fprintf() */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for sleep() */
#include <time.h>

int main(int argc, char *argv[])
{
    /* External error handling function */
    int sock;                         /* Socket */
    struct sockaddr_in multicastAddr; /* Multicast address */
    char *multicastlP;                /* IP Multicast address */
    unsigned short multicastPort;     /* Server port */
    char *sendString;                 /* String to multicast */
    unsigned char multicastTTL;       /* TTL of multicast packets */
    unsigned int sendStringLen;       /* Length of string to multicast */

    if ((argc < 4) || (argc > 5)) /* Test for correct number of parameters */
    {
        fprintf(stderr, "Usage' %s <Multicast Address> <Port> <Send String> [<TTL>]\n",
                argv[0]);
        exit(1);
    }
    multicastlP = argv[1];
    multicastPort = atoi(argv[2]);
    sendString = argv[3];
    /* First arg' multicast IP address */
    /* Second arg' multicast port */
    /* Third arg' string to multicast */
    if (argc == 5)                    /* Is TTL specified on command line? */
        multicastTTL = atoi(argv[4]); /* Command line specified TTL */
    else
        multicastTTL = 1; /* Default TTL = i */
    /* Create socket for sending/receiving datagrams */
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        fprintf(stderr, " socket () failed");
        return EXIT_FAILURE;
    }
    /* Set TTL of multicast packet */
    if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&multicastTTL, sizeof(multicastTTL)) < 0)
    {
        fprintf(stderr, " setsockopt () failed");
        return EXIT_FAILURE;
    }
    /* Construct local address structure */
    memset(&multicastAddr, 0, sizeof(multicastAddr));       /* Zero out structure */
    multicastAddr.sin_family = AF_INET;                     /* Internet address family */
    multicastAddr.sin_addr.s_addr = inet_addr(multicastlP); /* Multicast IP address */
    multicastAddr.sin_port = htons(multicastPort);          /* Multicast port */
    sendStringLen = strlen(sendString);                     /* Find length of sendString */

    time_t t;
    srand((unsigned) time(&t));
    int random;
    char buffer[1024];

    for (;;)                                                /* Run forever */
    {
        random = (rand() % 10) + 1;
        memset(buffer, 0, sizeof(buffer));

        snprintf(buffer, sizeof(buffer), "%d %s", random, sendString);
        sendStringLen = strlen(buffer);

        /* Multicast sendString in datagram to clients every 3 seconds */
        if (sendto(sock, buffer, sendStringLen, 0, (struct sockaddr *)&multicastAddr, sizeof(multicastAddr)) != sendStringLen)
        {
            fprintf(stderr, "sendto() sent a different number of bytes than expected");
            return EXIT_FAILURE;
        }
        sleep(3);
    }
}
/* NOT REACHED */
