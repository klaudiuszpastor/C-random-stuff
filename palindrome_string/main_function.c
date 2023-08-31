/* Check if a string is a palindrome */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palindrome_string(char string[])
{
    int middle = strlen(string) / 2;
    int lenght = strlen(string);

    for (int i = 0; i <middle; i++)
    {
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

    if (palindrome_string(stringiii) == true)
    {
        printf("%s - is palindrome",stringiii);
    }
    else 
    {
        printf("%s - is not palindrome",stringiii);
    }
    return 0;
}