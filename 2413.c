// Smallest even multiple
// EASY

#include <stdio.h>

int smallestEvenMultiple(int n) {
    return n % 2 ? n * 2 : n;
}