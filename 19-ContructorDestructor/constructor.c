#include <stdio.h>
 
void begin (void) __attribute__((constructor(101)));
void end (void) __attribute__((destructor(101)));

void begin2 (void) __attribute__((constructor(102)));
void end2 (void) __attribute__((destructor(102)));
 
int main (void)
{
  printf ("\nInside main ()");
}
 
void begin (void)
{
  printf ("\nIn begin ()");
}
 
void end (void)
{
  printf ("In end ()\n");
}

void begin2 (void)
{
  printf ("\nIn begin2 ()");
}
 
void end2 (void)
{
  printf ("\nIn end2 ()\n");
}
