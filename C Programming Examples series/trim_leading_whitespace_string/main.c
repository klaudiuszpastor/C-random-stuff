/* Trim leading whitespace string characters */

#include <stdio.h>

void trim(char *s);

int main(void){
    char s[] = "   \n\n\t   This is example.";

    printf("before: \n%s\n",s);
    trim(s);
    printf("after: \n%s\n",s);

    return 0;
}

void trim(char *s){
    int count = 0;
    // count the number of leading spaces
    while (s[count] == ' ' || s[count] == '\n' || s[count] == '\t') 
        count++;

    // if no whitespaces characters were found we don't do anything
    if (count != 0)
    {
        // shift the remainder of the string contents up by the number of leading
        // white space characters found
        int i = 0;
        while (s[i + count] != '\0')
        {
            s[i] = s[i + count];
            i++;
        }
        // terminate the string earlier given that the contents are being reduced,
        // the null terminator is shifted up by the number of leading whitespace 
        // characters as well
        s[i] = '\0';
    }
}