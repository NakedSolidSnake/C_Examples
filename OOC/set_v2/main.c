#include <stdio.h>
#include "new.h"
#include "object.h"
#include "set.h"

int main(int argc, char *argv[])
{
    int amount;
    void *s = new(Set);
    void *a = add(s, new(Object));
    void *b = add(s, new(Object));
    void *c = new(Object);

    if(contains(s, a) && contains(s, b))
        puts("ok");

    if(contains(s, c))
        puts("contains?");

    if(differ(a, add(s, a)))
        puts("differ?");

    amount = count (s);
    printf("Amount: %d\n", amount);

    if(contains(s, drop(s, a)))
        puts("drop?");


    
    delete(drop(s, b));
    delete(drop(s, c));

    amount = count (s);
    printf("Amount: %d\n", amount);

    return 0;
}