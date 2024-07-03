/* Print occurrences of characters */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_occurrences(char *s);

int main(){
    char s[] = "abcdefghijklmnopabcdefabcab";
    print_occurrences(s);
    return 0;
}

void print_occurrences(char *s){
    int lenght = strlen(s);
    char unique[lenght]; //keep track of how many unique characters found so far
    int counted = 0; //keep track of how many unique characters we've already counted
    // char unique is array that store int lennght numbers of characters
    for (int i=0; i < lenght; i++){
        bool already_counted = false;
        for (int j =0; j <counted; j++)
            if (s[i] == unique[j])
                already_counted = true;
        
        // if the character has already been counted, skip ahead to the next
        // iteration of the loop as we do not need to count it again
        if (already_counted) continue;

        int count =0;
        for (int j =0; j< lenght; j++)
            if (s[i] == s[j]) count++;
            printf("%c - %d\n",s[i],count);
            unique[counted] = s[i];
            counted++;
    
    }
}