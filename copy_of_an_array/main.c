/*Create a copy of an array with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h> 
// malloc and calloc allocate space dynammicly on heap


int *array_copy(int *array, int lenght);

int main(void){
    int a1[] = {1,2,3,4,5};
    int a2[] = {99,50,30,70,80,90,100,50};

    int *a1_copy = array_copy(a1,5);
    int *a2_copy = array_copy(a2,8);
    
    a1[0] = 10;
    a2[0] = 0;

    for (int i =0; i< 5; i++){
        printf("a1_copy[%d]=%d\n",i,a1_copy[i]);
    }
    printf("\n");
    for (int i =0; i< 8; i++){
        printf("a2_copy[%d]=%d\n",i,a2_copy[i]);
    }

    printf("\n");
    printf("a1: %p\na1_copy: %p\n",a1,a1_copy);

    // free allocated memory
    free(a1_copy);
    free(a2_copy);

    return 0;
}

// copy of the array of the given length on the heap
int *array_copy(int *array, int lenght){
    int *c = malloc(lenght * sizeof(int));
    for (int i =0; i <lenght; i++){
        c[i] = array[i];
    }
    return c;
}