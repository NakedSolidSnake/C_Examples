#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int time;
    if(argc != 3)
    {
        fprintf(stderr, "Usage : %s <message> <time>.\n", argv[0]);
        return EXIT_FAILURE;
    }

    time = atoi(argv[2]);
    printf("%s\n", argv[1]);
    printf("Waiting 5 seconds.\n");
    sleep(time);

    printf("%s with time = %d done.\n", argv[0], time);
    return EXIT_SUCCESS;
}
