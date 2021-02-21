#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct state State_t;
typedef void (*States)(State_t *state);

struct state{
    States state;
    int complete;
};

void exec(State_t *state);

void Phase1(State_t *state);
void Phase2(State_t *state);
void Phase3(State_t *state);
void Phase4(State_t *state);

int main(int argc, char const *argv[])
{
    State_t state = {
        .state = Phase1,
        .complete = 0
    };
    while(1)
    {
        exec(&state);
    }
    return 0;
}

void exec(State_t *state)
{
    state->state(state);
}

void Phase1(State_t *state)
{
    if(state->complete)
    {
        printf("Cicle is finished.\n");
        exit(0);
    }
    printf("Phase 1 t:1000\n");
    sleep(1);    
    state->state = Phase2;
}

void Phase2(State_t *state)
{
    printf("Phase 2 t:1000\n");
    sleep(1);
    state->state = Phase3;
}

void Phase3(State_t *state)
{
    printf("Phase 3 t:1000\n");
    sleep(1);
    state->state = Phase4;
}

void Phase4(State_t *state)
{
    printf("Phase 4 t:1000\n");
    sleep(1);
    state->state = Phase1;
    state->complete = 1;
}