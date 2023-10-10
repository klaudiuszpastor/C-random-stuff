/* Binary search algorithms */
/*Binary search works on sorted arrays. Binary search begins by comparing 
an element in the middle of the array with the target value. If the target 
value matches the element, its position in the array is returned. If the 
target value is less than the element, the search continues in the lower 
half of the array. If the target value is greater than the element, the 
search continues in the upper half of the array. By doing this, the 
algorithm eliminates the half in which the target value cannot lie in 
each iteration.
https://en.wikipedia.org/wiki/Binary_search_algorithm*/

#include <stdio.h>

int binary_search(int a[], int e, int l, int r);

int main(){
    int unsorted[] = {95,13,3,8,7,2,12,6,10,4,11,1};
    int sorted[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int index = binary_search(sorted,2,0,12);
    printf("index of 2: %d\n",index);

    return 0;
}


// Returns the index of element e in array a, searching for the element between 
// the left index l and right index r. Applies the binary search algorithm
// recursively to conduct the search. Returns -1 if element isn't in the array
int binary_search(int a[], int e, int l, int r){
    int mid = l + (r-1) / 2; //mid-way index between index l and index r
    if (l > r) return -1;
    if (a[mid] == e) return mid; //if we found the elemnt at the mid-way index
    else if (a[mid] > e) return binary_search(a, e, l, mid -1);
    // if the elemnt must be in the lft-portion of the portion of the
    // array we are currently looking at, search for it in this portion
    // if the elemnt must be in the right-portion of the portion of the
    // array we are currently looking at, search for it in this portion
    else 
        return binary_search(a,e,mid+1,r);
}
