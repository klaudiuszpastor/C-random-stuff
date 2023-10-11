/* Selection sort */
/*Selection sort is a sorting algorithm that 
selects the smallest element from an unsorted 
list in each iteration and places that element 
at the beginning of the unsorted list.*/

#include <stdio.h>


int main()
{
    int a[] = {5,9,7,6,4,0,2,3,8,1};
    int lenght = 10;

    for (int i = 0; i <lenght - 1; i++)
    {
        int min_pos = i;
        for (int j = i+1; j< lenght;j++)
            if (a[j] < a[min_pos]) min_pos = j;

        if (min_pos != i)
        {
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }

    for (int i =0; i <lenght; i++)
        printf("a[%d] = %d\n",i,a[i]);

    return 0;
}