// Valid anagram
// EASY

#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int countS = 0, countT = 0;
    long long int valS = 0, valT = 0;
    long long int valueS = 0, valueT = 0;
    while (s[countS] != '\0' && t[countT] != '\0') {
        valS += s[countS] * s[countS] * s[countS];
        valT += t[countT] * t[countT] * t[countT];
        valueS += s[countS] * s[countS];
        valueT += t[countT] * t[countT];
        countS ++;
        countT ++;
    }

    if (s[countS] != '\0' || t[countT] != '\0') {
        return false;
    }

    if (valueS == valueT && valS == valT) {
        return true;
    } else {
        return false;
    }
}