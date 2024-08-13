// Self dividing numbers
// EASY

#include <stdio.h>
#include <stdlib.h>

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* array = malloc((right - left) *sizeof(int));
    int pos = 0;
    for (int i = left; i <= right; i ++) {
        int x = i, flag = 0;
        while (x != 0) {
            if (x % 10 != 0 && i % (x % 10) == 0) {
                x /= 10;
            } else {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            array[pos ++] = i;
        }
    }

    *returnSize = pos;
    return array;
}