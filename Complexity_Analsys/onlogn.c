#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int call_times = 0;

int recursive_log_func(int n)
{
    if(n == 1)
        return 1;
    call_times++;
    int loop_duration = n;
    n = floor(n / 2);
    for(int i = 0; i < loop_duration ; i++)
    {
            //execute an arbritary function
    }
    return recursive_log_func(n);
}

int interactive_log_func(int n)
{
    call_times = 0;
    int loop_duration = n;
    while(n > 1)
    {
        call_times++;
        n = floor(n / 2);
        for(int i = 0; i < loop_duration ; i++)
        {
            //execute an arbritary function
        }
    }

    return call_times;    
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <integer number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int value = atoi(argv[1]);

    recursive_log_func(value);    
    printf("Recursion call times: %d\n", call_times);
    interactive_log_func(value);
    printf("Interactive call times: %d\n", call_times);
    return EXIT_SUCCESS;
}
