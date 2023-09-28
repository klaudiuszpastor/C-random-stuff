/*Flip a string's lowercase characters to uppercase and vice versa*/

#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main (void){
    char s[] = "abcdeABCDE";
    int lenght = strlen(s);

    for (int i =0; i < lenght; i++){
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
        else if (islower(s[i]))
            s[i] = toupper(s[i]);
    }

    printf("output: %s\n",s);
    return 0;
}