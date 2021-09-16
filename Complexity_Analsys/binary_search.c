#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool recursive_binary_search(int *array, int size, int target)
{
    int start = 0;
    int end = size - 1;

    int mid = (start + end) / 2;

    if(start > end)
        return false;

    if(array[mid] == target)
        return true;
    else 
    {
        if(array[mid] > target)
        {
            end = mid;
        }
        else 
        {
            start = mid;
        }

        return recursive_binary_search(&array[mid], size, target);
    }
}

// bool interactive_binary_search(int *array, int size, int target)
// {
//     int start = 0;
//     int end = size - 1;

//     while(start <= )
// }

int main(void)
{
    bool found;
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    found = recursive_binary_search(array, 10, 10);

    printf("%s\n", found ? "Target Found" : "Target not found");

    return EXIT_SUCCESS;
}

