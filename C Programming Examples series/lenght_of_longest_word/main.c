/* Find length of longest word in a string */

#include <stdio.h>
#include <string.h>

int largest_word(char *s);

int main(void){
    char s[] = "This is example.";
    int largest_lenght = largest_word(s);
    printf("%d\n", largest_lenght);
    return 0;
}

int largest_word(char *s){
    int lenght = strlen(s);

    // outer loop will control if we reached end of the string
    // two inner loops - first is goona step through the loop
    // second - will step through whatever separate the words
    // like period, space etc.
    int count = 0;
    int max = -1;
    char nonwords[] = " .;"; // characters that seperate words
    int i = 0;
    while (i<lenght){
        count = 0;
        while (i < lenght){
            if (strchr(nonwords, s[i]) != NULL)
                break;
        // we know we've reached the end of a word when strchr() no longer
        // returns NULL if it cannot find the char and a pointer
        // to the matching character if it can
            i++;
            count++;
            printf("lenght of the word: %d\n",count);
        }
        // if we've found a larger word than the previous largest word,
        // update the max value
        if (count > max) max = count;
        //if we've found a larger word than the previous largest word
        // update the max value
        while(i<lenght){
            if (strchr(nonwords, s[i]) == NULL) {
                break;
            }
        // once strchr() returns NULL, we know that s[i] is NOT one of the 
        // delimeter characters that separates words, and we have reached
        // the next word
            i++;
        }
    }
    return max;

}

/* The C library function 
char *strchr(const char *str, int c) searches for 
the first occurrence of the character c (an unsigned char) 
in the string pointed to by the argument str.

This returns a pointer to the first occurrence of the 
character c in the string str, or NULL if the character is not found.*/