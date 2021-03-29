#include <stdio.h>
#include <stdlib.h>

#define SSR_SIZE 8

void prin_data(char data, int mult);

int main(int argc, char const *argv[])
{
    unsigned char data[SSR_SIZE];

    for(int i = 0 ; i < SSR_SIZE; i++)
    {
        data[i] = 0xFF;
    }

    
    for(int i = 0 ; i < SSR_SIZE; i++)
    {
        // printf("%X", data[i]);
        prin_data(data[i], i * 10);
    }

    putchar('\n');

    
    
    return 0;
}


void prin_data(char data, int mult)
{
    for(int i = 0; i < SSR_SIZE; i++)
    {
        if(data >> i & 0x01)
            printf("Family %02d\tcode: %s\n", mult + i, "FFFFFFFFFFFFFFFF");
    }
}