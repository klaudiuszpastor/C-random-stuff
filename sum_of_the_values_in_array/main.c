/* Sum the values in an array */

#include <stdio.h>

int main(void)
{
    int array[] = {1,2,3,4,5,6,7,8,9};
    int lenght = 9;
    int sum = 0;

    for (int i=0; i<lenght; i++)
    {
        sum = sum + array[i];
    }
    printf("Sum of the array: %d",sum);

    return 0;
}