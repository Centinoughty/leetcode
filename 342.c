// Power of four
// EASY

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n) {
    if (n == 0) {
        return false;
    }
    
    double value = log10(n) / log10(4);
    return value == floor(value) ? true : false;
}