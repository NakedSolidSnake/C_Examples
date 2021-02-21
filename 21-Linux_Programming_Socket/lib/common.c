#include <common.h>
#include <stdarg.h>


void print_error(const char *error_message, ...)
{
  char buffer[MAX_BUF] = {0};
  va_list args;
  va_start(args, error_message);
  vsprintf(buffer, error_message, args);
  va_end(args);

  fprintf(stderr, buffer);
}