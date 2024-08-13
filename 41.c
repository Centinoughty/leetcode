// First missing positive
// HARD

#include <stdio.h>
#include <stdlib.h>

void countSort (int A[], int n, int pos) {
    int* count = (int*)calloc(10, sizeof(int));
    int* B = malloc(n * sizeof(int));

    for (int i = 0; i < n; i ++) {
        if (A[i] <= 0 || A[i] > n) {
            A[i] = 0;
        }

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
    for (int i = 1; i < n; i ++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    for (long int i = 1; max / i > 0; i *= 10) {
        countSort(A, n, i);
    }
}


int firstMissingPositive(int* nums, int numsSize) {
    int smallestPositive = 0, i;
    radixSort(nums, numsSize);
    for (i = 0; i < numsSize; i ++) {
        if (nums[i] == 0) {
            continue;
        } else if (nums[i] == smallestPositive) {
            continue;
        } else if (nums[i] == smallestPositive + 1) {
            smallestPositive ++;
        } else {
            break;
        }
    }

    if (i == numsSize) {
        return nums[numsSize - 1] + 1;
    }

    return smallestPositive + 1;
}