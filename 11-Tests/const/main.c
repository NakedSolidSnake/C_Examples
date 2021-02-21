#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int value;
    size_t size;
}Data_t;

void changeContent(const Data_t * data)
// void changeContent(Data_t * const data)
{
    // data->value = 10;
    // printf("Data = %d\n", data->value);
}

void changeReference(const Data_t * data)
{

}

size_t sizeOf(const void *self)
{
    const Data_t * const *cp = self;
    cp = (int *) 0x000000fff;
    return (*cp)->size;
}

int main(int argc, char *argv[])
{
    Data_t data;
    changeContent(&data);
    sizeOf(&data);
    return 0;
}
