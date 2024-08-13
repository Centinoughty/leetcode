// Length of last word
// EASY

#include <stdio.h>

int lengthOfLastWord(char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length ++;
    }

    int i = length - 1;
    int lastWordLength = 0;
    while (i >= 0) {
        if (s[i] == ' ' && lastWordLength == 0) {
            i --;
        } else if (isalpha(s[i])) {
            lastWordLength ++;
            i --;
        } else {
            break;
        }
    }

    return lastWordLength;
}