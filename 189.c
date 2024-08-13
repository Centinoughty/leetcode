// Rotate Array

#include <stdio.h>

// Step 1: created a new array
// Step 2: stored elements
// Step 3: stored from kth last element to last element and then from 1st to kth last element
// Step 4: stored back to the original array

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    if (numsSize - k) {
        int arr[numsSize - k];

        for (int i = 0; i < numsSize - k; i ++) {
            arr[i] = nums[i];
        }

        int j = 0;

        for (int i = numsSize - k; i < numsSize; i ++, j ++) {
            nums[j] = nums[i];
        }

        for (int i = 0; i < numsSize - k; i ++, j ++) {
            nums[j] = arr[i];
        }
    }
}


int main () {
    int n, k;
    scanf("%d", &n);
    int A[n];

    for (int i = 0; i < n; i ++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &k);
    rotate(A, n, k);
    for (int i = 0; i < n; i ++) {
        printf("%d ", A[i]);
    }
}


/*

void rotate (int* nums, int numsSize, int k) {
    int arr[numsSize];

    for (int i = 0; i < n; i ++) {
        arr[i] = nums[(i + k) % numsSize];
    }

    for (int i = 0;i < n; i ++) {
        nums[i] = arr[i];
    }
}

*/