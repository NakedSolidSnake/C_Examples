#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define SSR_SIZE 8

void prin_data(char data, int mult);

void handle_bit(unsigned char shift);

int main(int argc, char const *argv[])
{
    unsigned char data[SSR_SIZE];
    int shift = atoi(argv[1]);

    handle_bit(shift);

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

void handle_bit(unsigned char shift)
{
    uint64_t ssr = 0;
    // uint64_t ssr = 0x0123456789ABCDEF;
    char data[17] = {0};

    // ssr |= (1 << shift);

    // snprintf(data, 17, "%016lX", ssr);

    // printf("%s\n", data);

    for (int i = 0; i < 64; i++)
    {
        /* code */
        ssr |= (1 << i);
    }
    
    printf("%lX\n", ssr);

    snprintf(data, 17, "%lX", ssr);

    printf("%s\n", data);

    exit(0);
}
