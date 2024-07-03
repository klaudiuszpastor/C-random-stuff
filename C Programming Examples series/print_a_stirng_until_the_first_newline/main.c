/* Print a string until the first newline */

#include <stdio.h>

void print_until(char *s);

int main(){
    char s[] = "This is example. \n And....";
    print_until(s);
    printf("\n");
    return 0;
}

void print_until(char *s){
    // loop through each char in the string, using putchar() to print
    // the char, up until we encounter either the first newline char
    // or reach the end of the string
    int i = 0;
    while (s[i] != '\n' && s[i] != '\0'){
        putchar(s[i]);
        i++;
    }
}