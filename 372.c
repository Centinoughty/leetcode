// Super pow
// MEDIUM

#include <stdio.h>

int superPow(int a, int* b, int bSize) {
    long long int exponent = 0, result = 1;
    for (int i = 0; i < bSize; i ++) {
        exponent = (exponent * 10 + b[i]) <= 1140 ? (exponent * 10 + b[i]) : (exponent * 10 + b[i]) % 1140;
    }
    
    for (int i = 0; i < exponent; i ++) {
        result = (result * a) % 1337;
    }

    return result % 1337;
}