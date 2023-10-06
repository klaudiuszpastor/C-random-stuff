/* Merge two sorted arrays */

#include <stdio.h>

void merge_array(int a1[],int la1,int a2[],int la2, int result[]);

int main (void){
    int a1[] = {1,3,8,9,10,12};
    int a2[] = {2,4,5,11};
    int r[10];
    merge_array(a1,6,a2,4,r);

    for (int i=0;i<10;i++){
        printf("r[%d] = %d\n",i,r[i]);
    }
    return 0;
}


void merge_array(int a1[],int la1,int a2[],int la2, int result[]){
    // counter variables
    int i =0, j=0, k=0;

    while (i < la1 && j < la2){
        if (a1[i] < a2[j]){ 
            result[k] = a1[i];
            k++;
            i++;
        }
        else{
            result[k] = a2[j];
            k++;
            j++;
        }
    }

    //cleanup elements that left in arrays
    // we don't know in whitch array there are still numbers
    // after first loop
    // that's why we implement these next two loop that
    // store elements in result array

    while (i<la1){
        result[k] = a1[i];
        k++;
        i++;
    }
    while (j<la2){
        result[k] = a2[j];
        k++;
        j++;
    }
}