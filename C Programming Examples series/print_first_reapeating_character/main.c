/* Print first repeating character demonstration */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_first_repeat(char *s);

int main() {
    char s[] = "abcdefghb";

    print_first_repeat(s);
    return 0;
}

void print_first_repeat(char *s){
    int lenght = strlen(s);
    bool found_repeat = false;

    for (int i=0; i <lenght; i++){
        for (int j=0; j <lenght; j++)
            if (s[i] == s[j] && i != j)
                found_repeat = true;
        
        if (found_repeat){
            printf("%c\n",s[i]);
            break;
        }
    }

    if (!found_repeat)
        printf("None repeating characters");
}

