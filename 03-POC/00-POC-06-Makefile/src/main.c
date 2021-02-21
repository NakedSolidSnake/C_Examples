#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "log.h"

int main(int argc, char *argv[])
{

   double s = sum(1.5, 5.50);
   log(0, "SUM DONE!\n");
   return 0;
}
