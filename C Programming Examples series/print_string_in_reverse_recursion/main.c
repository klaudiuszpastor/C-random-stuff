#include <stdio.h>


void print_revers (char *s);

int main(){
    char s[] = "This is example.";
    print_revers(s);
    printf("\n");
    return 0;
}

void print_revers (char *s){
// stop recursive function calls once we reach null terminator
    if (*s != '\0'){
// before printing the current character, call the function
// with a pointer to the next character

//because we always call the function pointing to the next 
// charachter before we print the character, we'll end up printing the
// last charcter first, then the 2nd last, and on and one as
// we "unroll" the stack of recursive function calls..
        print_revers(s+1);
        printf("%c", *s);
    }
}