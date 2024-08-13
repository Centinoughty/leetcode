// Sum of square numbers
// MEDIUM

#include <stdio.h>
#include <stdbool.h>

bool judgeSquareSum(int c) {
    long long int left = 0;
    long long int right = sqrt(c);
    while (left <= right) {
        if (left * left + right * right == c) {
            return true;
        } else if (left * left + right * right > c) {
            right --;
        } else {
            left ++;
        }
    }

    return false;
}