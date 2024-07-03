/* Verify password requirements */

// at least 8 characters long
// at least 1 uppercase letter
// at least 1 lowercase letter
// at least 1 digit
// at least 1 symbol

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool verify_password(char *p);


int main(){
    char p[] = "Abcdef1@";
    bool result = verify_password(p);
    if (result) printf("Verified password\n");
    else printf("Invalid password");

    return 0;
}

bool verify_password(char *p){
    int len = strlen(p);
    if (len < 8) return false;

    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_symbol = false;

    for (int i = 0; i <len; i++){
        if (isupper(p[i])) return true;
        if (islower(p[i])) return true;
        if (ispunct(p[i])) return true;
        if (isdigit(p[i])) return true;
    }

    if (!has_symbol) return false;
    if (!has_digit) return false;
    if (!has_upper) return false;
    if (!has_lower) return false;

    return true;
}