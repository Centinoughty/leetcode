// Number of steps to reduce a number to zero
// EASY

#include <stdio.h>

int numberOfSteps(int num) {
    int count = 0;
    if (num == 0) {
        return 0;
    }
    while (num > 0) {
        if (num % 2 == 1) {
            count ++;
        }
        count ++;
        num /= 2;
    }

    return count - 1;
}