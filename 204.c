// Count primes
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int countPrimes(int n) {
    int* array = (int*)malloc(n * sizeof(int));
    int count = 0;
    for (int i = 2; i < n; i ++) {
        array[i] = 0;
    }

    for (int i = 2; i < n; i ++) {
        if (array[i] == 0) {
            count ++;
            for (int j = 2; j * i < n; j ++) {
                array[i * j] = 1;
            }
        }
    }

    free(array);
    return count;
}