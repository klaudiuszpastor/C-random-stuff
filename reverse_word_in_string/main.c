/* How to reverse the words in a string */

#include <stdio.h>
#include <string.h>

void reverse_word(char *s);

int main (void){

    char s[] = "This is example.";
    printf("before: %s\n", s);

    reverse_word(s);
    printf("after: %s\n",s);

    return 0;
}

void reverse_word(char *s){
    int lenght = strlen(s);
    int i = 0, j=0; //counter variables

    // temporary character array
    char temp[100];


    for (i =0; i<lenght; i++)
    {   //outer loop is focused on if we have reached the end of the string
        // keeping track if we reached end of the string
        for (j=0; j<lenght; j++, i++)
        { //this loop uses j as a counter variable to keep
        // track of the next word of the lenght and store the next word into temp
            if (s[i] == ' ' || s[i] == '.') break; // we stop when this conditions
            // (if we reach end of the next word we stop)
            temp[j] = s[i];
        }
    

        while (j>0)
        {
            j--;
            s[i - j - 1] =temp[j];
        }
    }
}