/* Insersion sort algorithm */

/* Insertion sort iterates, consuming one input element each repetition, 
and grows a sorted output list. At each iteration, insertion sort removes 
one element from the input data, finds the location it belongs within the 
sorted list, and inserts it there. It repeats until no input elements remain.

Sorting is typically done in-place, by iterating up the array, growing the 
sorted list behind it. At each array-position, it checks the value there 
against the largest value in the sorted list (which happens to be next to it, 
in the previous array-position checked). If larger, it leaves the element in 
place and moves to the next. If smaller, it finds the correct position within 
the sorted list, shifts all the larger values up to make a space, and inserts 
into that correct position. ~wikipedia*/

#include <stdio.h>
#include <string.h>

void insertion_sort(int array[], int lenght);

int main (void){
    int array[] = {7,2,3,9,6,5,1,4,8,0};
    int lenght = 10;

    printf("before: \n");
    for (int i=0; i<lenght; i++)
        printf("a[%d] = %d\n", i,array[i]);
    printf("\n\nafter: \n");

    insertion_sort(array,10);
    for (int i=0; i<lenght; i++)
        printf("a[%d] = %d\n", i,array[i]);

    return 0;
}

void insertion_sort(int array[], int lenght){
    int i = 1, j = 1;
    for (i; i<lenght; i++){
        // inner loop sfits over elements on the sorted left hand side 
        // until the correct sorted position for the temp is found, at 
        // which point we place it there
        int temp = array[i];
        j = i-1;
        while (j>=0 && array[j] > temp){
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = temp;
    }
}
//https://en.wikipedia.org/wiki/Insertion_sort