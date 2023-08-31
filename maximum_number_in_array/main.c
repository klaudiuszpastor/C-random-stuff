/*Find the maximum number in an array*/

#include <stdio.h>

int main(void)
{
    int myarray[] = {2,3,6,8,0,-1,-2,-5};
    int max;

    max = myarray[0]; //assume first number is the maximum

    for (int i = 0; i<8; i++) // i++ is incrementing by 1
    {
        if (myarray[i] > max) 
        {
            max= myarray[i];
        }
        // check every number in array
        // if number in array is greater than max, make max new number

    }
    printf("Maximum: %d\n",max);
    return 0;
}
