/* Sum the values in an array */
/* function */

#include <stdio.h>

int sum(int array[], int lenght)
{
    int sum = 0;

    for (int i=0; i<lenght; i++)
    {
        sum = sum + array[i];
    }
    printf("Sum of the array: %d",sum);

    return sum;
}



int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9};
    int summ = sum(array,9);

    return 0;
}