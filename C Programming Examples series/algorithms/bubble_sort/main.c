/* Bubble sort algorithm */
/*Bubble sort, sometimes referred to as sinking sort, is a simple sorting 
algorithm that repeatedly steps through the input list element by element, 
comparing the current element with the one after it, swapping their values if needed. 
These passes through the list are repeated until no swaps had to be performed during 
a pass, meaning that the list has become fully sorted. The algorithm, which is a 
comparison sort, is named for the way the larger elements "bubble" up to the 
top of the list.*/

#include <stdio.h>

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

    for (int i=0; i<lenght; i++){
        for (int j=0; j < (lenght -1); j++){
            if (array[j] > array[j+1]){ // if < we will have reverse order
                int temp = array[j]; //we store array[j] in temporary variable to not overwrite it later
                array[j] = array[j+1]; //we overwrite first value that is smaller then next one
                array[j+1] = temp; // then we overwite bigger value with temporary value
            }
        }
    }
}