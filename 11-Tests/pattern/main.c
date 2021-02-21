#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void pattern(int max, int n);

int main(int argc, char *argv[]) 
{

    int n = atoi(argv[1]);
    // scanf("%d", &n);
  	// Complete the code to print the pattern.
    int max = n * 2 - 1;
   
    pattern(max, n);
    
    
    return 0;
}

void pattern(int max, int n)
{
    int temp = n;
    int flag = 0;

    for(int line = 0; line < (max); line++)
    {
        if(line == 0 || line == (max - 1)){
            for(int col = 0; col < max; col++)
            {
                printf("%d ", n);            
            }
        }else{
            flag = 0;
            temp = n;
            for(int col = 0; col < max; col++)
            {
                printf("%d ", temp);
                if(temp == 1)
                    flag = 1;
                
                if(flag)
                    temp++;
                else
                    temp--;
            }
        }
        
        printf("\n");
    }  
}