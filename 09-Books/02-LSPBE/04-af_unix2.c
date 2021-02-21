#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>

static void bail(const char *on_what)
{
  perror(on_what);
  exit(1);
}

int main(int argc, char **argv, char **envp)
{
  int z;
  int sck_unix;
  struct sockaddr_un adr_unix;
  int len_unix;
  const char pth_unix[] = "Z*MY-SOCKET*";

  sck_unix = socket(AF_UNIX, SOCK_STREAM, 0);

  if(sck_unix == -1)
    bail("socket()");

  memset(&adr_unix, 0, sizeof(adr_unix));

  adr_unix.sun_family = AF_UNIX;

  strncpy(adr_unix.sun_path, pth_unix, sizeof(adr_unix.sun_path) - 1)[sizeof(adr_unix.sun_path) - 1] = 0;

  len_unix = SUN_LEN(&adr_unix);

  adr_unix.sun_path[0] = 0;

  z = bind(sck_unix, (struct sockaddr *)&adr_unix, len_unix);
  if(z == -1)
    bail("bind()");

  system("netstat -pa --unix 2>/dev/null | sed -n '/^Active UNIX/, /^Proto/p;/af_unix/p'");

  close(sck_unix);
  return 0;
}
