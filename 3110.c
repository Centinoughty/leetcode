// Score of a string

#include <stdio.h>

int scoreOfString(char* s) {
    int i = 0, sum = 0;
    while (s[i + 1] != '\0') {
        int difference = s[i] > s[i + 1] ? s[i] - s[i + 1] : s[i + 1] - s[i];
        sum += difference;
        i ++;
    }

    return sum;
}