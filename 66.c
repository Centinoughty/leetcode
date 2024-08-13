// Plus one
// EASY

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* array = (int*)malloc((digitsSize + 1) * sizeof(int));
    array[digitsSize] = (digits[digitsSize - 1] + 1) % 10;
    int carry = (digits[digitsSize - 1] + 1) / 10;
    int i = digitsSize - 2;
    while (i >= 0) {
        array[i + 1] = (digits[i] + carry) % 10;
        carry = (digits[i] + carry) / 10;
        i --;
    }

    array[0] = carry;
    if (array[0] == 0) {
        for (int i = 0; i < digitsSize; i ++) {
            array[i] = array[i + 1];
        }
        
        *returnSize = digitsSize;
    } else {
        *returnSize = digitsSize + 1;
    }

    return array;
}