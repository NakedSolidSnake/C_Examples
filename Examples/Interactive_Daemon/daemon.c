#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h>
#include <syslog.h> 

int main(int argc, char const *argv[])
{
    int fd;
    int state = 0, old_state = -1;
    char buffer[2];
    char * myfifo = "/tmp/daemon_file";

    mkfifo(myfifo, 0666);

    while(1)
    {
        fd = open(myfifo,O_RDONLY); 
		read(fd, buffer, 2);
		close(fd); 
        state = atoi(buffer);

        if(state != old_state)
        {            
            old_state = state;
            openlog("daemon", LOG_PID | LOG_CONS , LOG_USER);
            syslog(LOG_INFO, "LED Status: %s", state ? "On": "Off");
            closelog();            
        }
    }
    
    return 0;
}
