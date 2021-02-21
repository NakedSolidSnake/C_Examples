#include <stdio.h>
#include <stdlib.h>

void call_lambda(void);

int main(int argc, char *argv[])
{
    call_lambda();
    return 0;
}

void call_lambda(void)
{
    void print_message(int value){
        printf ("Sum result %d.\n", value);
    }

    int soma(int num1, int num2)
    {
        return num1 + num2;
    }

    int (*call)(int, int) = soma;
    

    print_message(call(10, 10));
}
