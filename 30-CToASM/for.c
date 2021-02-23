#include <stdio.h>

typedef void(*Func)(void);

typedef struct 
{
    int id;
    Func func;
} Table;

void func1(void);
void func2(void);
void func3(void);
void func4(void);

int main(int argc, char const *argv[])
{
    const Table table[] = 
    {
        {.id = 0, .func = func1},
        {.id = 1, .func = func2},
        {.id = 2, .func = func3},
        {.id = 3, .func = func4},
    };

    int table_items = sizeof(table)/sizeof(table[0]);

    for(int i = 0; i < table_items; i++)
    {
        table[i].func();
        break;
    }

    return 0;
}

void func1(void)
{
    printf("func1.\n");
}

void func2(void)
{
    printf("func2.\n");
}

void func3(void)
{
    printf("func3.\n");
}

void func4(void)
{
    printf("func4.\n");
}