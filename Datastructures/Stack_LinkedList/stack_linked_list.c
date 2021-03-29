#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define STACK_EMPTY     INT_MIN

typedef struct node
{
    int value;
    struct node *next;
} node;

node *head = NULL;

bool push(int value)
{
    node *new_node = malloc(sizeof(node));
    if(!new_node)
        return false;

    new_node->value = value;
    new_node->next = head;
    head = new_node;

    return true;
}

int pop(){
    if(head == NULL)
        return STACK_EMPTY;

    int result = head->value;
    node *tmp = head;
    head = head->next;
    free(tmp);
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


