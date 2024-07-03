/* Find minimum occurring character */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_min_char(char *s);

int main(){
    // test the function where h is minimum
    char s[] = "abcdefghabcdefghabcdefg";
    print_min_char(s);
    return 0;
}

void print_min_char(char *s){
    int len = strlen(s);
    char unique[len];
    int counted = 0;
    int min_count;
    char min_char;

    for (int i=0; i<len; i++){
        // check if char is already counted
        bool already_counted = false; 
        for (int j =0; j<counted; j++)
            if (s[i] == unique[j])
                already_counted = true;
        
        // if char has already been counted, skip the remained of the loop
        if (already_counted) continue;

        int count = 0;
        for (int j=0; j<len;j++)
            if (s[i] == s[j]) count++;
        
        // add the char to the array of already counted characters
        unique[counted] = s[i];
        counted++;

        //determine if this is the new minimum occuring char
        if (counted == 1){
            min_count = count;
            min_char = s[i];
        }
        else if (count < min_count){
            min_count = count;
            min_char = s[i];
        }
    }


if (len>0)
    printf("%c:%d\n", min_char, min_count);
    else
    printf("string has 0 lenght\n");
}