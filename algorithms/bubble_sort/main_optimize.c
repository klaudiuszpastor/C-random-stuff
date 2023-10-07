/* Bubble sort algorithm */

#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int a[],int lenght);

int main (void){
    int array[] = {5,4,2,7,8,9,1,3,6,0};
    int lenght = 10;

    bubble_sort(array,lenght);

    for (int i=0; i < lenght; i++){
        printf("array[%d] = %d\n",i,array[i]);
    }

    return 0;
}

void bubble_sort(int array[],int lenght){

    bool swapped = false;
    int i = 0;

    // The outer loop will continue to attempt to sort the array so long as it 
    // may still be out of order.  We know the array might still be out of order
    // if a swap has taken place... if no swap has taken place, we know that the
    // array is sorted.  So we used the bool swapped to keep track of whether a 
    // swap has taken place, and to decide when to terminate the algorithm.
    do 
    {
        swapped = false;

        // The inner loop makes a pass through the array elements, and if any 
        // element and the element next to it are out of order, it swaps them. 
        // After the first pass through the array, we know for sure that the last 
        // element of the array is sorted, and after the 2nd pass through we know 
        // for that the 2nd last element of the array is sorted... and so we can 
        // progressively pass through less elements of the array each time we run 
        // this loop.  We use i to keep track of how many passes through the array 
        // we have made, and lessen the number of elements we go through each time!
        for (int j = 0; j < (lenght - 1 - i); j++)
        {
            // we could flip < to > to have it sort in ascending order instead of 
            // descending order as it will now
            if (array[j] < array[j + 1])
            {
            // swaps elements that are detected to be out of order using a temporary
            // variable to store one value before we need to overwrite it with the
            // other, see: https://en.wikipedia.org/wiki/Swap_(computer_programming)
            int temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
            swapped = true;
            } 
        }
        i++;
    } while (swapped);
}

/*iteration-statement:  do statement while ( expression ) ;

The expression in a do-while statement is evaluated after the body of the loop is executed. 
Therefore, the body of the loop is always executed at least once.
The expression must have arithmetic or pointer type. Execution proceeds as follows:
1. The statement body is executed.
2. Next, expression is evaluated. If expression is false, the do-while statement terminates 
and control passes to the next statement in the program. If expression is true (nonzero), 
the process is repeated, beginning with step 1.

The do-while statement can also terminate when a break, goto, or return statement is executed 
within the statement body.*/