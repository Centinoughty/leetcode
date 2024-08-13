// Search Insert Position

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (target > nums[numsSize - 1]) {
        return numsSize;
    } else if (target < nums[0]) {
        return 0;
    }
    return right;
    
}


int main () {
    int n, r;
    scanf("%d", &n);
    int A[n];

    for (int i = 0; i < n; i ++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &r);

    printf("%d", searchInsert(A, n, r));
}