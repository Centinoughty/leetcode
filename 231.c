// Power of two
// EASY

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n == 0) {
        return false;
    }
    return log2(n) == floor(log2(n)) ? true : false;
}

// return n > 0 && (n & n - 1) == 0;