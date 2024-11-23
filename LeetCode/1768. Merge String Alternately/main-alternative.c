#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *mergeAlternately(char *word1, char *word2) {
	int len1 = strlen(word1);
	int len2 = strlen(word2);

	char maxLen = len1 + len2;
	char *merged = (char *)malloc((maxLen + 1) * sizeof(char));

	int i = 0, j = 0, k = 0;
	for (; i < len1 || j < len2; k++) {
		if (i < len1) merged[k++] = word1[i++];
		if (j < len2) merged[k++] = word2[j++];
	}

	merged[k] = '\0';
	return merged;
}

int main() {
	char *word1 = "abcdef";
	char *word2 = "pqr"; 
	char *merged = mergeAlternately(word1, word2); 
	printf("%s\n", merged);
	free(merged);
	return 0;
}
