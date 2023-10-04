/*String Format Validation using canadian postal codes */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool is_postal_code (char postal_code[]);

int main(void){
    char code1[] = "KL8 GW2";
    if (is_postal_code(code1))
        printf("%s is a postal code\n",code1);
    else
        printf("%s is not a postal code\n",code1);
    return 0;
}

bool is_postal_code(char postal_code[]){
    if (strlen(postal_code) != 7) return false;
    if (!isalpha(postal_code[0]))  return false;
    //we are checking is letter is A to Z (is alphabetic)
    if (!isalpha(postal_code[1])) return false;
    if (!isdigit(postal_code[2])) return false;
    if (postal_code[3] != ' ') return false;
    if (!isalpha(postal_code[4]))  return false;
    if (!isalpha(postal_code[5])) return false;
    if (!isdigit(postal_code[6])) return false;

    return true;
}