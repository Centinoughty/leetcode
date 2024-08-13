// Water and jug problem
// MEDIUM

#include <stdio.h>
#include <stdbool.h>

int gcd (int a, int b) {
    if (a == b) {
        return a;
    } else if (a > b) {
        return gcd(b, a - b);
    } else {
        return gcd(b, a);
    }
}


bool canMeasureWater(int x, int y, int target) {
    if (target <= x + y) {
        if (x % 2 == 0 && y % 2 == 0 && target % 2 == 1) {
            return false;
        } else {
            if (target % gcd(x, y) == 0) {
                return true;
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
}