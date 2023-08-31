/* Compute the avarage of an array */
/* function */

#include <stdio.h>

double avg_of_array(double array[],int lenght)
{
    double sum = 0;
    double avarage = 0;
    for (int i = 0; i<lenght; i++ )
    {
        sum += array[i];
    }
    avarage = sum/lenght ;

    return avarage;
}

int main(void)
{
    double array[] = {2.2,6.8,1.2,8.9,2.7,5.3};
    double av = avg_of_array(array,6);
    printf("avarage of array: %.2f ",av);
    return 0;
}