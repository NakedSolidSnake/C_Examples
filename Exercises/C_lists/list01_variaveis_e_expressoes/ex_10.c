#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float km_h;
    float m_s;

    printf("Type a Speed in km.:");
    scanf("%f", &km_h);

    m_s = km_h / 3.6;
    printf("The Speed in m/s is %f m/s.\n", m_s);
    return EXIT_SUCCESS;
}