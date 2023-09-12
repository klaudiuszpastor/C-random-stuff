// String append with dynamic memory allocation

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *string_append(char *s1, char *s2);

int main(void){
    char first[20] = "First ";
    char second[10] = "Second";

    strcat(first,second);
    printf("first: %s\n", first);


    char s1[] = "abc";
    char s2[] = "wxyz";
    char *s = string_append(s1,s2);
    printf("s: %s\n",s);
    free(s); // free memory
    return 0;
}
// s1 - "abc"  - s1_length = 3
// a b c \0 <- data
// 0 1 2 3  <- indexes
// s2 - "wxyz" - s2_length = 4
// w x y z \0 <- data
// 0 1 2 3 4  <- indexes
// s
// a b c w x y z \0
// 0 1 2 3 4 5 6 7 <- indexes

char *string_append(char *s1, char *s2){
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);
    int size = s1_length + s2_length + 1; //plus null terminator
    char *s = calloc(size, sizeof(char));
    // calloc allocates the requested memory and returns a pointer to it
    // the difference in malloc and calloc is that malloc does not
    // set the memory to zero where as calloc sets allocated memory to 
    // zero

    for (int i = 0; i< s1_length; i++){
        s[i] = s1[i];
    }
    for (int i=0; i < s2_length; i++){
        s[s1_length + i] = s2[i];
    }
    // null terminator

    s[size - 1] = '\0';

    return s;
}
