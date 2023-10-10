/* Find lenght of smallest word in a string */

#include <stdio.h>
#include <string.h>


int smallest_word (char *s);

int main(){
    char s[] = "This is example.";
    int count = smallest_word(s);
    printf("Smallest word: %d\n",count);
    return 0;
}

int smallest_word (char *s){
    int len = strlen(s);
    int count = 0;
    int min = 100;
    int i =0;
    char nonwords[] = " ."; //delimeter characters


    // the outer loop stops when we reach the end of the string, 
    // it has a loop that steps through the next word, followed
    // by a loop that steps through any delimeter characters
    // that separate words
    while (i<len){
        count = 0;
        while (i<len){
            if (strchr(nonwords, s[i]) != NULL) break;
            count++;
            i++;
        } 

        if (count < min) min = count;

    // once strchr() returns NULL, we know that s[i] is NOT
    // one of the delimeter characters that separates words, 
    // and we have reached the next word
        while (i< len){
            if (strchr(nonwords, s[i]) == NULL) break;
            i++;
        }
    }
    return min;

}