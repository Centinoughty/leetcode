// Integer replacement
// MEDIUM

#include <stdio.h>

int integerReplacement(int n) {
    long int x = n;
    int count = 0;
    while (x != 1) {
        if (x % 2 == 0) {
            x /= 2;
        } else if ((x / 2) % 2 == 0 || x / 2 == 1) {
            x --;
        } else {
            x ++;
        }
        count ++;
    }

    return count;
}