/*Find the maximum number in an array*/
/*Function find_max*/

#include <stdio.h>

int find_max(int array[],int lenght)
{
    int max;
    max = array[0]; 
    for (int i = 0; i< lenght; i++) 
    {
        if (array[i] > max) 
        {
            max = array[i];
        }
    }
    return max;
}

