#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float km_h;
    float m_s;

    printf("Type a Speed in m_s.:");
    scanf("%f", &m_s);

    km_h = m_s * 3.6;

    printf("The Speed in km/h is %f km/h.\n", km_h);

    return EXIT_SUCCESS;
}