#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float latitude;
    float longitude;
    char info[80];

    while(scanf("%f,%f,%79s[^\n]", &latitude, &longitude, info) == 3)
    {
        printf("{\"latitude\": %f,\"longitude\": %f, \"info\": %s},\n", latitude, longitude, info);
    }
    return 0;
}
