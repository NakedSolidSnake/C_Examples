#include <syslog.h>
#include <stdio.h>
#include <unistd.h>

void log(const char *module, const char *log_message)
{
  openlog(module, LOG_PID | LOG_CONS, LOG_USER);
  syslog(LOG_INFO, log_message);
  closelog();
  return;
}

