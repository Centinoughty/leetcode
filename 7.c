// Reverse integer

#include <stdio.h>
#include <limits.h>

int reverse(int x){
    long int sum = 0, sign = 1;
    sign = x < 0 ? -1 : 1;
    x *= sign;
    while (x > 0) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }

    if (sum > INT_MAX || sum < INT_MIN) {
        return 0;
    }

    return sign * sum;
}