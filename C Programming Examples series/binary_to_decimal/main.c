// converting a string representation of a binary number to decimals

#include <stdio.h>
#include <string.h>

int convert(char *string);


int main(void)
{
    char s1[] = "10101";
    int val = convert(s1);
    printf("s1 in dec: %d\n",val);
    return 0;
}

int convert(char *string){
    int slen = strlen(string);
    int total = 0;
    int decval = 1; //current 2^n value of the digit 

    for (int i = (slen -1); i>=0; i--){
        if (string[i] == '1') total += decval;
        decval *= 2;
    }
    return total;
}