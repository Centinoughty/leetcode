// Reverse prefix of a word
// EASY

#include <stdio.h>
#include <stdlib.h>

char* reversePrefix(char* word, char ch) {
    int left = 0;
    int right = 0;
    while (word[right] != ch) {
        if (word[right] == '\0') {
            return word;
        }

        right ++;
    }

    char* modified = (char*)malloc((right + 1) * sizeof(char));
    for (int i = right; i >= 0; i --) {
        modified[right - i] = word[i];
    }

    for (int i = 0; i <= right; i ++) {
        word[i] = modified[i];
    }

    free(modified);
    return word;
}