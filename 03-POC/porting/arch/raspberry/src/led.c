#include <led.h>
#include <wiringPi.h>

int LED_init(void)
{
  wiringPiSetup();
  pinMode(LED, OUTPUT);
  return 0;
}

int LED_turnOn(void)
{
  digitalWrite(LED, HIGH);
  return 0;
}

int LED_turnOff(void)
{
  digitalWrite(LED, LOW);
  return 0 ;
}


