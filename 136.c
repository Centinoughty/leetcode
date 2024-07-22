// Single number
#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int required = 0;
    for (int i = 0; i < numsSize; i ++) {
        required ^= nums[i];
    }

    return required;
}


int main () {
    int n;
    scanf("%d", &n);\
    int A[n];
    
    for (int i = 0; i < n; i ++) {
        scanf("%d", &A[i]);
    }
}