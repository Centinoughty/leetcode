// Number of changing keys
// EASY

#include <stdio.h>
#include <ctype.h>

int countKeyChanges(char* s) {
    int i = 0, count = 0;
    char letter = tolower(s[0]);

    while (s[i] != '\0') {
        if (isalpha(s[i])) {
            char lower = tolower(s[i]);
            if (letter != lower) {
                count ++;
                letter = tolower(s[i]);
            }
        }

        i ++;
    }

    return count;
}