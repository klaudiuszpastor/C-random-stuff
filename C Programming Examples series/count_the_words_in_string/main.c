/* Count the words in a string */

#include <stdio.h>
#include <string.h>

int word_count(char *s);

int main(){

    char s[] = "This is example.";
    int count = word_count(s);
    printf("Words in string: %d\n",count);

    return 0;
}

int word_count(char *s){
    int len = strlen(s);
    int count = 0;
    char nonwords[] = " .,;";
    
    for (int i = 0; i< len; i++){ //step through the each character
    // in the string with i as an index
        while (i<len) { // step through the next word (if there is one)
            if (strchr(nonwords, s[i]) != NULL) break;
            // strchr() will return NULL if the char s[i] cannot be found
            // in nonwords, which means so long as it 'is' returning NULL, 
            i++;
        }
        count++; //increment count as we have stepped through another word

        while (i<len){
            // when we can't find the character of our current string
            // index in nonwords, then the function will return NULL, and
            // we'll know we've reached the next word and will continue on 
            // to step through it in the next pass of the loop
            if (strchr(nonwords, s[i]) == NULL) break;
            i++;
        }
    }
    return count;
}