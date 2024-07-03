/* Compute the avarage of an array */
/* double stands for double precision floating point numbers. This means that 
such a number usually takes up twice as much space in memory as a float */

#include <stdio.h>

int main(void)
{
    double array[] = {2.2,6.8,1.2,8.9,2.7,5.3};
    double sum = 0;
    int lenght = 6;
    double avarage = 0;

    for (int i = 0; i<6; i++ )
    {
        sum += array[i];
    }
    avarage = sum/lenght ;

    printf("avarage of array: %.2f ",avarage);

    return 0;   
}