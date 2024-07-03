/* Program that prints its own source code */

#include <stdio.h>

int main (void){

    FILE *fp; //file pointes
    char p; //variable that stores each character in file
    // __FILE__ is a preprocessor macro that will be set with the name of the source
    // code file 'r' means it's in reading mode
    fp = fopen(__FILE__,"r");

    // read in each char of the file, store it into c and then print it, until 
    // the char is set to EOF by getc() which signifies the End Of File
    while ((p = getc(fp)) != EOF) putchar(p);
    fclose(fp);

    return 0;
}

