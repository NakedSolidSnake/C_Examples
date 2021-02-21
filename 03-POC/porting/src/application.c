#include <stdlib.h>
#include <application.h>
#include <led.h>
#include <unistd.h>

int App_init(void)
{
  LED_init();
  return 0;
}

int App_exec(void)
{
  while(1)
  {
    LED_turnOn();
    sleep(1);
    LED_turnOff();
    sleep(1);
  }
  return 0;
}

int main(int argc, char *argv[])
{
  App_init();
  App_exec();

  return EXIT_SUCCESS;
}
