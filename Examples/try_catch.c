#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>



int exception = 0;
jmp_buf savebuf;

#define try if((exception = setjmp(savebuf)) == 0)
#define catch(exception_value) else if(exception == exception_value)
#define catchall else
#define throw(exception_value) longjmp(savebuf, exception_value)

double compute_average(double *values, size_t length)
{
    double sum = 0.0;

    if(length == 0)
        // longjmp(savebuf, 1);
        throw(1);


    throw(5);

    for (int i = 0; i < length; i++)
    {
        /* code */
        sum += values[i];
    }

    return sum / length;
    
}

int main (int argc, char *argv[])
{
    int array_len = argc - 1;

    double *array_double = (double *)malloc(array_len * sizeof(double));

    for (int i = 0; i < array_len; i++)
    {
        /* code */
        array_double[i] = atof(argv[1 + i]);
    }

    // if(setjmp(savebuf) == 0)
    try
    {
        double avg = compute_average(array_double, array_len);

        printf("average = %lf.\n", avg);
    }
    catch(5){
        printf("Error five.\n");
    }
    catchall {
        printf("Error!.\n");
    }

    
    
}