#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESG_LEN_MAX    10

char message[MESG_LEN_MAX] = "message";
char password[MESG_LEN_MAX] = "password";

int main(int argc, char const *argv[])
{
    if(argc != 3){
        printf("Usage: %s <password> <message>\n", argv[0]);
        return 1;
    }

    strcpy(message, argv[2]);

    if(!strcmp(argv[1], password)){
        printf("Access granted.\n");
        printf("Message: %s\n", message);
        return 0;
    }
    
    printf("Access Denied.\n");
    return 1;    
}
