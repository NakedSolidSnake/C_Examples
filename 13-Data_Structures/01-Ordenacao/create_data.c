#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{    
    int data_amount;

    srand(time(NULL));

    printf("Enter data amount: ");
    scanf("%d", &data_amount);

    if(data_amount > 0){
        printf("{");
        for(int i = 0; i < data_amount; i++){

            if(i % 10 == 0)
                printf("\n");
            if(i == (data_amount - 1))
                printf("%3d", rand() % 1000);
            else
                printf("%3d, ", rand() % 1000);
        }

        printf("\n}\n");
    }

    return 0;
}
