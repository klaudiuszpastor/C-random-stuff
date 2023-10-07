/* Manually find the lenght of a stirng */

#include <stdio.h>
#include <string.h>


int lenght_of_string (char *string);

int main (void) {
    char *s = "This is a example.";
    int lenght_of_s = strlen(s);
    printf("Lenght of string %d\n",lenght_of_s);

    int our_string = lenght_of_string(s);
    printf("Lenght of string: %d\n",our_string);
    return 0;
}

int lenght_of_string (char *string){
    int i=0; //lenght of a stirng 
    while (string[i] != '\0') i++;
    return i;
}