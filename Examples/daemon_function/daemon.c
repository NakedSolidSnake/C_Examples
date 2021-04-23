#include <stdio.h>
#include <syslog.h>
#include <unistd.h>
#include <stdbool.h>

void call_log(int counter)
{
    openlog("Daemon", LOG_PID | LOG_CONS , LOG_USER);
    syslog(LOG_INFO, "Counter : %d", counter);
    closelog();
}

int main(int argc, char *argv[])
{
    int i = 0;

    daemon(0, 0);    
    
    while(true)
    {
        call_log(i++);
        sleep(1);
    }
    return 0;
}
