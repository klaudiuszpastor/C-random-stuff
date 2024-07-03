/* Compute Standard Deviation */
#include <stdio.h>
#include <math.h>

double stdev(double x[], int N);

int main()
{
    double a[] = {9.2,1.5,6.7,8.2,5.5,7.1};
    double result = stdev(a,6);
    printf("result: %lf\n",result);
    return 0;
}

double stdev(double x[], int N){
    double mean = 0, total = 0;
    for (int i=0; i <N; i++) total += x[i];
    mean = total / N;

    double sum =0;
    for (int i = 0 ;i<N;i++)
        sum += pow(x[i] - mean, 2);

    return sqrt(sum / N);
}