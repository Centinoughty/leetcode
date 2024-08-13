// Maximise happiness of selected children
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

void countSort (int A[], int n, int pos) {
    int* count = calloc(10, sizeof(int));
    int* B = malloc(n * sizeof(int));

    for (int i = 0; i < n; i ++) {
        count[(A[i] / pos) % 10] ++;
    }

    for (int i = 1; i < 10; i ++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i --) {
        B[-- count[(A[i] / pos) % 10]] = A[i];
    }

    for (int i = 0; i < n; i ++) {
        A[i] = B[i];
    }

    free(count);
    free(B);
}


void radixSort (int A[], int n) {
    int max = A[0];
    for (int i = 0; i < n; i ++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    for (int i = 1; max / i > 0; i *= 10) {
        countSort(A, n, i);
    }
}


long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    long long int result = 0;
    int end = happinessSize - 1;
    int downValue = 0;

    radixSort(happiness, happinessSize);

    for (int i = 0; i < k; i ++) {
        if (happiness[end] - downValue >= 0) {
            result += happiness[end] - downValue;
        }

        end --;
        downValue ++;
    }

    return result;
}