#include <stdio.h>
// A normal function with an int parameter and void return type
void fun(int a) {
    printf("Values of a is %d",a);
}

int main() {
    // fun_ptr is a pointer to function fun()
    void (*fun_ptr)(int) = &fun;
    /*
    void (*fun_ptr)(int);
    fun_ptr = &fun;
    */
   // Invoking fun() using fun_ptr
   (*fun_ptr)(10);

   return 0;
}
/*
1) Unlike normal pointers, a function pointer points to code, not data. 
Typically a function pointer stores the start of executable code.
2) Unlike normal pointers, we do not allocate de-allocate memory using 
function pointers.
3) A function’s name can also be used to get functions’ address. For example, 
in the below program, we have removed address operator ‘&’ in assignment. 
We have also changed function call by removing *, the program still works.
*/