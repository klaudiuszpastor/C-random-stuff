/*Find the minimum number in an array*/

#include <stdio.h>

int main(void)
{
    int myarray[] = {2,3,6,8,0,-1,-2,-5};
    int min;

    min = myarray[0]; //assume first number is the minimum

    for (int i = 0; i<8; i++) // i++ is incrementing by 1
    {
        if (myarray[i] < min) 
        {
            min= myarray[i];
        }
        // check every number in array
        // if number in array is less than min, make min new number

    }
    printf("Minimum: %d\n",min);
    return 0;
}

