// String to integer (atoi)
// MEDIUM

#include <stdio.h>
#include <limits.h>

int myAtoi(char* s) {
    long int number = 0;
    int sign = 1, i = 0;

    while (s[i] == ' ') {
        i ++;
    }

    if (s[i] == '+' || s[i] == '-') {
        sign = s[i ++] == '+' ? 1 : -1;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        number = number * 10 + s[i ++] - '0';
        if (sign * number > INT_MAX) {
            return INT_MAX;
        } else if (sign * number < INT_MIN) {
            return INT_MIN;
        }
    }

    return sign * number;
}