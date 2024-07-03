/* Count the occurrences of a value in an array*/
/* function */

#include <stdio.h>

int count_occurrences(int array[],int lenght, int number)
{
    int count = 0;
    for (int i=0; i<lenght; i++)
    {
        if (array[i] == number) 
        {
            count = count + 1; 
        }
    }
    return count;
}


// testing function
int main(void)
{
    int myarray[] = {1,1,1,1,2,3,4,5,6,7,0};
    int find = count_occurrences(myarray,10,1);
    
    printf("Number of ones: %d\n",find);
    return 0;
}
