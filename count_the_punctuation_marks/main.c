/* Count the punctuation marks in a string */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_punct(char *s);

int main()
{
    char s[] = "apple,pear,orange; something...";
    int total = count_punct(s);
    printf("total: %d\n",total);
    return 0;
}

int count_punct(char *s){
    int len = strlen(s);
    int count = 0;
    for (int i=0;i<len;i++)
        if (ispunct(s[i])) count++;
    return count;
}