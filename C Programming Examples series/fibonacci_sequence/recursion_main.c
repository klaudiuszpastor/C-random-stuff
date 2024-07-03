/*Computing the Fibonacci sequence */
/* Fibonacci sequence: the sequence of numbers created by the sum
of the two previous numbers, starting with 0 and 1.*/


// recursion approach

#include <stdio.h>

int fib(int n)
{
    if (n>1) return fib(n-1) + fib(n-2);
    else if (n==1) return 1;
    else if (n==0) return 0;
    else 
    {
        printf("Error - n must be >=0\n");
        return -1;
    }
}