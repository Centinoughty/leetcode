// Divide two integers
// MEDIUM

#include <stdio.h>
#include <limits.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    } else if (dividend == INT_MIN && divisor == 1) {
        return INT_MIN;
    }

    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    long long int x = labs(dividend), y = labs(divisor);
    int quotient = 0;

    while (x >= y) {
        long long int i = y, j = 1;
        while (x >= (i << 1)) {
            i <<= 1;
            j <<= 1;
        }

        x -= i;
        quotient += j;
    }

    quotient = sign == 1 ? quotient : -quotient;
    return quotient;
}