#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    const char * const hello = "hello";

    printf("%p %p %p\n", hello, &hello, hello);
    printf("%p %p %p\n", hello + 1, &hello + 1, hello + 1);
    return 0;
}
