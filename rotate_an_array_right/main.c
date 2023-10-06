/* Rotate an array to the right */

#include <stdio.h>

void rotate_array_to_right(int array[],int lenght);
void rotate_n_number_times(int array[],int lenght, int n);

int main (void){
    int a1[] = {1,2,3,4,5,6,7,8,9};

    printf("\n\nBefore rotation\n");
    for (int i=0;i<9;i++) 
        printf("a1[%d] = %d\n",i,a1[i]);

    rotate_n_number_times(a1,9,1);
    printf("\n\nAfter rotation\n");
    for (int i=0;i<9;i++) 
        printf("a1[%d] = %d\n",i,a1[i]);

    return 0;
}

void rotate_array_to_right(int array[],int lenght){
    int temp = array[lenght-1]; //temporary last element of an array
    for (int i = (lenght - 2); i>=0; i--)
        array[i+1] = array[i]; // shift everything to the right
        array[0] = temp;
    
}

void rotate_n_number_times(int array[],int lenght, int n){
    for (int i=0;i<n; i++) 
        rotate_array_to_right(array,lenght);
}

