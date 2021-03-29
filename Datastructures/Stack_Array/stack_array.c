#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH    5
#define EMPTY           (-1)
#define STACK_EMPTY     INT_MIN

int mystack[STACK_LENGTH];
int top = EMPTY;

bool push(int value)
{
    if(top >= STACK_LENGTH - 1)
        return false;

    top++;
    mystack[top] = value;
    return true;
}

int pop(){
    if(top == EMPTY)
        return STACK_EMPTY;

    int result = mystack[top];
    top--;
    return result;
}

int main(int argc, char const *argv[])
{
    push(56);
    push(78);
    push(13);

    int t;
    t = pop();
    while(t != STACK_EMPTY)
    {
        printf("%d\n", t);
        t = pop();
    }
    return 0;
}


