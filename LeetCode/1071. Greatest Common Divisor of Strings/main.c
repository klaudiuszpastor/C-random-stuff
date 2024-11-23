#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
1. Check if both words have gcd:
	- Connect st1 + str2 and str2 + str1
	- if both words are different, words have no gcd and we return ""
2. Find the length of gcd
3. Find the dividor
*/


int gcd(int a, int b) {
	while(b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int isMultiple (const char* str, const char* sub, int subLen) {
    int strLen = strlen(str);

    if (strLen % subLen != 0) {
        return 0;
    }

    for (int i = 0; i < strLen; i++) {
        if (str[i] != sub[i % subLen]) {
            return 0;
        }
    }

    return 1;
}

char *gcdOfStrings(char *str1, char *str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int maxLen = len1 + len2;

	char *word1 = (char*)malloc((maxLen + 1) * sizeof(char));
	char *word2 = (char*)malloc((maxLen + 1) * sizeof(char));
	
	strcpy(word1, str1);
	strcat(word1, str2);
	strcpy(word2, str2);
	strcat(word2, str1);

	if (strcmp(word1, word2) != 0) {
		free(word1);
		free(word2);
		return "";
	}

	int gcdLen = gcd(len1, len2);

	char *result = (char*)malloc((gcdLen + 1) *sizeof(char));
	strncpy(result, str1, gcdLen);
	result[gcdLen] = '\0';

	if (isMultiple(str1 , result, gcdLen) && isMultiple(str2, result, gcdLen)) {
		return result;
	}

	free(result);
	return "";
}


int main() {
    const char* str1 = "ABCABC";
    const char* str2 = "ABC";

    printf("%s\n", gcdOfStrings(str1, str2)); // Output: "ABC"

    const char* str3 = "ABABAB";
    const char* str4 = "ABAB";

    printf("%s\n", gcdOfStrings(str3, str4)); // Output: "AB"

    const char* str5 = "LEET";
    const char* str6 = "CODE";

    printf("%s\n", gcdOfStrings(str5, str6)); // Output: ""

    return 0;
}
