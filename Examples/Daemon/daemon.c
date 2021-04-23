#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <syslog.h>

void call_log(int counter)
{
    openlog("Daemon", LOG_PID | LOG_CONS , LOG_USER);
    syslog(LOG_INFO, "Counter : %d", counter);
    closelog();
}

int main(int argc, char* argv[])
{
  pid_t process_id = 0;
  pid_t sid = 0;

  process_id = fork();
  if(process_id < 0)
  {
    printf("fork falhou.\n");
    exit(1);
  }

  if(process_id > 0)
  {
    printf("PID do processo filho %d\n", process_id);
    exit(0);
  }

  umask(0);

  sid = setsid();
  if(sid < 0)
  {
    exit(1);
  }

  chdir("/");

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);


  int i = 0;

  while(1)
  {
    call_log(i++);
    sleep(1);
  }
  
  return 0;
}
