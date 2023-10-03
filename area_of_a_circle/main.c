#include <stdio.h>

int main(void){
    double radius = 0;
    printf("Enter radius: ");
    scanf("%lf",&radius);
    double area = 3.141592 * radius * radius;
    printf("area: %f\n",area);

    return 0;
}