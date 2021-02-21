#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int split_sum(int i);

int main(int argc, char *argv[]) {
	
    int n = atoi(argv[1]);    
    //Complete the code to calculate the sum of the five digits on n.
    printf("%d\n", split_sum(n));
    return 0;
}

int split_sum(int i)
{
    int temp = i;
    int sum = 0;

    for(; temp != 0;)
    {
        sum += temp % 10;
        temp = temp /10;
    }

    return sum;
}
