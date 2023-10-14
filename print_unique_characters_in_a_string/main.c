/* Print first unique character in a string */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_first_unique(char *s);

int main() {
    char s[] = "abcdefghiklmnopabcdefghi";  
    print_first_unique(s);

    return 0;
}

void print_first_unique(char *s){

    int length = strlen(s);
    bool found_repeat = false;
    bool found_unique = false;

    for (int i = 0; i <length; i++){
        found_repeat = false;
        for (int j =0; j <length; j++)
            if (s[i] == s[j] && i!=j)
                found_repeat = true;
        
        if (!found_repeat){
            printf("%c\n",s[i]);
            found_unique = true;
            break;
        }
    }

    if (!found_unique)
        printf("No unique characters\n");
}