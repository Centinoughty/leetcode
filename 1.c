// Two Sum

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* arr = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize -1; i ++) {
        for (int j = i + 1; j < numsSize; j ++) {
            if (nums[i] + nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
        }
    }
    
    return arr;
}


int main () {
    int n;
    scanf("%d", &n);
    int A[n];
    int* arr;

    for (int i = 0; i < n; i ++) {
        scanf("%d", &A[i]);
    }

    arr = twoSum(A, n, 6, A);
    printf("%d %d", arr[0], arr[1]);
}