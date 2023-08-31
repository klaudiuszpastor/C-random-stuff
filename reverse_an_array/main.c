/* Reverse An Array */

#include <stdio.h>

int main(void)
{
    int arrayToReverse[] = {9,8,7,6,5,4,3,2,1};
    int lenght = 9;
    int temp = 0;

    for (int i=0; i < (lenght/2); i++)
    {
        temp = arrayToReverse[i];
        arrayToReverse[i] = arrayToReverse[lenght - i - 1];
        arrayToReverse[lenght - i - 1] = temp;
    }
    
    for (int i=0; i<lenght; i++ )
    {
        printf(" %d " ,arrayToReverse[i]);
    }

    return 0;

}