/* Reverse An Array */
/* function */

#include <stdio.h>

int reverse_array(int array[],int lenght)
{
    int temp = 0;

    for (int i=0; i < (lenght/2); i++)
    {
        temp = array[i];
        array[i] = array[lenght - i - 1];
        array[lenght - i - 1] = temp;
    }
    
    for (int i=0; i<lenght; i++ )
    {
        printf(" %d " ,array[i]);
    }

    return 0;

}


// test function
int main(void)
{
    int arrayToReverse[] = {1,2,3,4,5,6,7,8,9};
    int reverse = reverse_array(arrayToReverse,9);
    return 0;

}