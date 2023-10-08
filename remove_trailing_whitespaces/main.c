/* Remove trailing whitespaces string characters */

#include <stdio.h>
#include <string.h>

void remove_whitespaces(char *s);

int main(void){
    char s[] = "This is example. \n\n\t";

    printf("before: %s\n ",s);

    remove_whitespaces(s);
    printf("after: %s\n",s);

    return 0;
}

void remove_whitespaces(char *s){
    int i = strlen(s) - 1; //start at the last index of the string that is not null terminator

    // unless we are in the end of the string keep examing indexes
    while (i >= 0){

    if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') 
        i--;
    else break;
    }
    // set null terminator at the end of the string
    s[i+1] = '\0';
}