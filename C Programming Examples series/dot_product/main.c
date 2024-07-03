// an example of computing a dot product in C
// dot prduct examples

// v1 = (2,5,4)
// v2 = (3,2,1)
// r = (2*3) + (5 *2 ) + (4*1) = 20

#include <stdio.h>

float dot_product(float v1[],float v2[], int length);

int main(void){
    float v1[] = {2,5,4};
    float v2[] = {3,2,1};
    float result = dot_product(v1,v2,3);
    printf("Result: %f\n",result);

    return 0;
}

float dot_product(float v1[],float v2[], int length){
    float sum = 0;
    for (int i = 0; i<length; i++){
        sum += (v1[i] * v2[i]);
    }
    return sum;
}


