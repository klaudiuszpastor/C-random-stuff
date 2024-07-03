/*Find the minimum number in an array*/
/*Function find_minimum*/

#include <stdio.h>

int find_minimum(int array[],int lenght)
{
    int min;
    min = array[0]; 
    for (int i = 0; i< lenght; i++) 
    {
        if (array[i] < min) 
        {
            min= array[i];
        }
    }
    return min;
}








