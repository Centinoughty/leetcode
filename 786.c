// K-th smallest prime fraction
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

double binary_search(int* arr, int arrSize, int k) {
    double left = 0.0, right = 1.0;
    double mid;

    while (right - left > 1e-9) {
        mid = left + (right - left) / 2.0;
        int count = 0;
        int p = 0, q = 1;

        for (int i = 0, j = 0; i < arrSize; i++) {
            while (j < arrSize && arr[i] > mid * arr[j]) {
                j++;
            }
            count += arrSize - j;
            if (j < arrSize && p * arr[j] < q * arr[i]) {
                p = arr[i];
                q = arr[j];
            }
        }

        if (count == k) return p * 1.0 / q;
        else if (count < k) left = mid;
        else right = mid;
    }

    return -1;
}

int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize) {
    double target = binary_search(arr, arrSize, k);

    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            double fraction = arr[i] * 1.0 / arr[j];
            if (fraction == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = arr[i];
                result[1] = arr[j];
                *returnSize = 2;
                return result;
            }
        }
    }

    return NULL;
}