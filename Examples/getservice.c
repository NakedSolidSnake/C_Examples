#include <netdb.h>
#include <stdio.h>

//To this code works the service and alias must be present in /etc/services

int main()
{
     struct servent *serv = getservbyname("myserver", "tcp");
     printf("name: %s\n", serv->s_name);
     printf("Port: %d\n", ntohs(serv->s_port));
     return 0;
}