/* We are checking if arrays are disjoint. */

#include <stdbool.h>
#include <stdio.h>

bool is_disjoint(int a1[],int la1, int a2[], int la2);

int main (void){
    int a1[] = {1,3,5,6,7,8,10};
    int a2[] = {3,4,11,12,13,10,1};

    if (is_disjoint(a1,7,a2,7)){
        printf("Arrays are disjoint\n");
    }
    else 
        printf("Arrays are not disjoint\n");

    return 0;
}

bool is_disjoint(int a1[],int la1, int a2[], int la2){
    for (int i=0; i<la1;i++){
        for (int j=0; j<la2; j++){
            if (a1[i] == a2[j]) return false;
        }
    }
    return true;
}