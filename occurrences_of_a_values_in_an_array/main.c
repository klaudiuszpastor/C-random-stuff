/* Count the occurrences of a value in an array*/

#include <stdio.h>

int main(void)
{
    int array[] = {1,2,4,6,6,7,8,3,0,5,10};
    int count = 0;
    int number = 6;

    
    for (int i=0; i<11; i++)
    {
        if (array[i] == number) 
        {
            count = count + 1; // or count++
        }
    }

    printf("Number of 6s in array found: %d\n",count);
    return 0;
}