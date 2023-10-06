/* Count non-repeating elements in array */

#include <stdio.h>

int non_repeating(int array[],int lenght);

int main(void){
    int a[] = {1,2,3,3,4,5,7,7,8,10,10};
    int cc = non_repeating(a,11);
    printf("Count: %d\n",cc);
    return 0;
}

// function returns non repeating elements of array
int non_repeating(int array[],int lenght){
    //counter variables
    int i=0, j=0, count = 0;

    for (i = 0; i<lenght; i++){
        for (j=0; j<lenght; j++)
            if (array[i] == array[j] && i!=j) break;
            // if j is equal to the length that means the inner loop did not find a 
            // match (otherwise we would've break'd out of the loop before j reaches 
            // the length), in which case we've found a non-repeating element and we 
            // increment count
            if (j == lenght) count++;
    }
    return count;
}