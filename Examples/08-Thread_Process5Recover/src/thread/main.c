#include <pthread.h>
#include <common.h>
#include <program_a.h>
#include <program_b.h>
#include <unistd.h>

/*
    Verify threads in a process throught terminal 
    $ top -H -p <pid>
*/

typedef struct threadList
{
    pthread_t thread;
    Function_t function;
    const char *name;
}threadList_st;

static threadList_st tList[] = 
{
    {.function = program_a, .name = "program_a"},
    {.function = program_b, .name = "program_b"}
};

static int threads_amount = sizeof(tList)/sizeof(tList[0]);


int main(int argc, char const *argv[])
{

    for(int i = 0; i < threads_amount; i++){
        pthread_create(&tList[i].thread, NULL, tList[i].function, NULL);
        pthread_setname_np(tList[i].thread, tList[i].name);
    }

    for(int i = 0; i < threads_amount; i++){
        pthread_join(tList[i].thread, NULL);
    }

    return 0;
}
