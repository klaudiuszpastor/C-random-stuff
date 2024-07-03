/*Computing the Fibonacci sequence */
/* Fibonacci sequence: the sequence of numbers created by the sum
of the two previous numbers, starting with 0 and 1.*/


// iterative approach

#include <stdio.h>

int main (void)
{
    int term1 =0;
    int term2 = 1;
    int fibn = 0;
    int lenght = 0;

    do
    {
        printf("Enter sequence lenght: ");
        scanf("%d",&lenght);
        if (lenght<3)
        {
            printf("Lenght must be >3\n");
        }
    }
    while (lenght < 3);

    printf("Solution\n");
    printf("%d,%d,",term1,term2);

    for (int i =2; i<lenght; i++)
    {
        fibn = term1 + term2;
        printf("%d",fibn);
        term1 = term2;
        term2 = fibn;

        if (i != (lenght-1)) printf(",");
        else printf("\n");
    }

    return 0;
}