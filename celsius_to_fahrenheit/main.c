/* Convert Celsius to Fahrenheit */
/* Multiply by 1.8 (or 9/5 ) and add 32*/
/* scanf is a function that stands for Scan Formatted String. It is used 
to read data from stdin (standard input stream i.e. usually keyboard) and 
then writes the result into the given arguments. It accepts character, string, 
and numeric data from the user using standard input. Scanf also uses format 
specifiers like printf.*/
#include <stdio.h>

int main (void)
{
    double C = 0;
    double F = 0;
    double start = 0;
    double end = 0;
    double step = 0;
    

    printf("Enter starting C temp: ");
    scanf("%lf",&start);

    printf("Enter ending C temp: ");
    scanf("%lf",&end);

    printf("Enter step C temp: ");
    scanf("%lf",&step);

    for ( C= start; C <= end; C+= step )
    {
        F = ((C * 1.8)) + 32;
        printf("C: %8.2lf -> F: %8.2lf\n",C,F);
    }

    return 0;
}