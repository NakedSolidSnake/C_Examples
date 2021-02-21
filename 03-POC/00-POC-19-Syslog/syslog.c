#include <syslog.h>

int main()
{
  openlog("PROGRAMA SYSLOG", LOG_CONS | LOG_PID | LOG_NDELAY , LOG_LOCAL0);

  syslog(LOG_INFO, "%s", "Mensagem do Cristiano");

  closelog();

  return 0;
}
