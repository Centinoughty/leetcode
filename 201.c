// Bitwise AND of numbers range

#include <stdio.h>

int rangeBitwiseAnd(int left, int right) {
    int count=0;
    while(left!=right){
        left=left>>1;
        right=right>>1;
        count++;
    }
    return left<<count;
}