// Divisible and non-divisible sums difference
// EASY

#include <stdio.h>

int differenceOfSums(int n, int m) {
    int ans = (n * (n + 1) / 2) - m * ((n / m) * ((n / m) + 1));
    return ans;
}