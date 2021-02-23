#include <stdio.h>
#include <unistd.h>
#include <poll.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main(int argc, char *argv[])
{
  char buffer[MAX];
  struct pollfd fds[2];
  int ret = -1;

  while(1)
  {
    /* Clear all events */
    memset(&fds,0, sizeof(fds));
    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    fds[1].fd = STDOUT_FILENO;
    fds[1].events = POLLIN;

    ret = poll(fds, 2, 1000 * 10);

    if(ret == -1)
    {
      perror("pool");
      return 1;
    }

    if(ret == 0)
    {
      perror("timeout");
      return 1;
    }
    
    if(fds[0].revents & POLLIN)
    {
      read(fds[0].fd, buffer, 1);
      printf("Stdin read event\n");
    }

    if(fds[1].revents & POLLOUT)
    {
      printf("Stdout write event\n");
    }
  }
}
