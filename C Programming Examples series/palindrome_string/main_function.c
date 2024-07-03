/* Check if a string is a palindrome */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palindrome_string(char string[])
{
    int middle = strlen(string) / 2;
    int lenght = strlen(string);
    printf("lenght of string = %d\n",lenght);

    for (int i = 0; i <middle; i++)
    {   
        for(int j=0;j<lenght;j++){
        printf("string[%d = %c] == %c \n",j,string[j],string[lenght - j - 1]);
        }
        if (string[i] == string[lenght - i - 1])
        
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main(void)
{
    char stringi[] = "madam";
    char stringii[] = "racer";
    char stringiii[] = "abc"; 
    
    if (palindrome_string(stringi) == true)
    {
        printf("%s - is palindrome",stringi);
    }
    else 
    {
        printf("%s - is not palindrome",stringi);
    }
    return 0;
}