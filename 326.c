// Power of three
// EASY

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfThree(int n) {
    if (n == 0) {
        return false;
    }

    double value = log10(n) / log10(3);
    return value == floor(value) ? true : false;
}