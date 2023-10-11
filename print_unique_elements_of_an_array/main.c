/* Print unique elements of an array */

#include <stdio.h>
#include <stdbool.h>

void print_unique(int a[], int length);

int main(){
    int a[] = {1,2,3,4,5,6,3,4,1,8,9,7,8};
    print_unique(a,13);

    return 0;
}

void print_unique(int a[], int lenght){
    for (int i=0; i <lenght; i++){
        bool match_found = false;
        for (int j=0; j<lenght; j++){ //if we find a matching elements
        // that is not the same element then the elemnt is not unique
            if (a[i] == a[j] && i!=j)
                match_found = true;
        }
        if (match_found == false) printf("%d\n",a[i]);
        // only print out the element if it is NOT unique
    }
}
