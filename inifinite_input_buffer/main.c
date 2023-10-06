/*"inifinite" input buffer*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define BUFFER_SIZE 5

int main(void){
    int size = 2;   
    int *buffer = malloc(sizeof(int)*size); 
    /* */
    int input = 0;
    int num_data = 0;
    while (true){

        if (num_data==size){
            size *=2;
            buffer = realloc(buffer, sizeof(int)*size);
        }
        printf("Enter:");
        scanf("%d", &input);   

        if (input == -1) break;
        else buffer [num_data] = input;
        num_data++;
    }
    int total = 0;
    for (int i = 0; i < num_data; i++){
    printf("buffer[%d]=%d\n", i, buffer[i]);
    total += buffer[i];
    }
    printf("Average: %d\n", total / num_data);
    printf("Num data: %d\n", num_data);
    printf("Buffer size: %d\n", size);
    return 0;
}