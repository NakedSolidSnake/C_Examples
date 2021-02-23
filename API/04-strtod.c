#include <stdio.h>  /* printf, NULL */
#include <stdlib.h> /* strtod */

int main(int argc, char *argv[])
{
    double v1, v2;

    
    if(argc != 4 ){

        fprintf(stderr, "Error parameters is different.\n" 
        "Usage.: %s param1 param2\n", argv[0]);
        return EXIT_FAILURE;
    }

    
    v1 = strtod(argv[2], NULL);
    v2 = strtod(argv[3], NULL);

    printf("Values catpured v1: %lf v2: %lf\n", v1, v2);
    
    return 0;
}