#include <stdio.h>
#include <string.h>
#include <ctype.h> 

void lower_to_upper (char *s);

#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main (void){
    char s1[] = "jfnesifbISUBEFIUBWw";
    char s2[] = "jawodBAEBDIieufiwb";
    lower_to_upper(s1);
    lower_to_upper(s2);

    printf("output: %s\n",s1);
    printf("output: %s\n",s2);
    return 0;
}

void lower_to_upper (char *s){
    
    int lenght = strlen(s);

    for (int i =0; i < lenght; i++){
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
        else if (islower(s[i]))
            s[i] = toupper(s[i]);
    }
    
}

