/* Remove all vowels from a string */

#include <stdio.h>
#include <string.h>


int main (void){

    char s[] = "This is example string";
    int curpos = 0; // current position in string
    int newpos = 0; // new position in string

    while (curpos < strlen(s)){ // iterate throught the lenght of a string
        // we are checking every position
        // newpos refers to the new string that we are creating
        if (!(s[curpos] == 'a' || s[curpos] == 'e'||
            s[curpos] == 'o' || s[curpos] == 'i'||
            s[curpos] == 'u')) {
                s[newpos] = s[curpos];
                newpos++;
            }
        curpos++;
    } 
    // shifting up the null terminator to newpos because the string
    // will be shorter - we just ending string with null terminator
    s[newpos] = '\0';

    printf("string: %s \n",s);

    return 0;
}