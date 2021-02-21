#include <common.h>
#include <sys/types.h>
#include <sys/socket.h>



int main()
{
    int sock_ret;
    int socks[2];

    sock_ret = socketpair(AF_LOCAL, SOCK_STREAM, 0, socks);
    if(sock_ret == ERROR){
        print_error("%s socketpair(AF_LOCAL,SOCK_STREAM,0)\n", strerror(errno));
        return EXIT_FAILURE;
    }

    printf("s[0] = %d;\n", socks[0]);
    printf("s[1] = %d;\n", socks[1]);

    system("netstat --unix -p");
    return 0;
}
