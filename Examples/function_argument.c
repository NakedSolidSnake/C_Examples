#include <stdio.h>
#include <stdlib.h>

typedef int (*compare)(void *param1, void *param2);

void whoIsGreater(compare comp, void *param1, void *param2);

int myCompare(void *val1, void *val2);

int main(int argc, char *argv[])
{
    /* code */
    int number1 = 10;
    int number2 = 10;

    whoIsGreater(myCompare, &number1, &number2);


    return 0;
}


void whoIsGreater(compare comp, void *param1, void *param2)
{
    int ret  = comp(param1, param2);
    if(ret == 0){
        printf("The values are equal.\n");
    }else if(ret > 0){
        printf("Param 1 is greater than Param 2");
    }else{
        printf("Param 2 is greater than Param 1");
    }
}

int myCompare(void *val1, void *val2)
{
    int _val1 = *(int *)val1;
    int _val2 = *(int *)val2;

    if(_val1 == _val2)
        return 0;
    if(_val1 > _val2)
        return 1;

    if(_val1 < _val2)
        return -1;
}