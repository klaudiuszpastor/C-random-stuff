/* Output a triangle of stars */

#include <stdio.h>

int main(void){
    for (int i =1; i<=10;i++){ //outer line its gonna output new line
        for (int j =1; j<= i; j++){ //inner output
            printf("*");
        }
        printf("\n");
    } 
}