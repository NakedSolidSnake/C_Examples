#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(int argc, char const *argv[])
{
    int t;
    if(argc != 3)
        return EXIT_FAILURE;

    t = atoi(argv[2]);

    while(1)
    {
        openlog("LOGS: ", LOG_PID | LOG_CONS , LOG_USER);
        syslog(LOG_INFO,"%s", argv[1]);
        closelog();

        sleep(t);
    }    
    return 0;
}
