// counting the occurrences of a word in a string

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int word_count(char *string, char *word);

int main (void){
    char s[] = "It is in this string once";
    char w[] = "It";
    int result = word_count(s,w);

    printf("Result: %d\n",result);

    char s1[] = "It is in in in this string once";
    char w1[] = "in";
    int result1 = word_count(s1,w1);

    printf("Result: %d\n",result1);

    return 0;
}

int word_count(char *string,char *word){

    int slen = strlen(string);
    int wlen = strlen(word);
    // end at the position in the string where the word could not
    // longer fit
    int end = slen - wlen + 1;
    int count = 0;

    // the outer loop ensures we check each postion in the string
    // for the word
    for (int i =0; i<end ;i++){
        bool word_found = true;

        //inner loop checks for the word at this postion in the string
        // by checking if each character in the word matches
        // character in the string  (i being the in the string, and j
        // the position in the word, by adding i+j we check the corresponding
        // character in the string) 
        for (int j =0; j<wlen;j++)
        {
            if (word[j] != string[i+j]){
                word_found = false;
                break;
            }

        }
        if (word_found) count++;
    }
    return count;
}