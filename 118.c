// Pascal's triangle
// EASY

#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** array = (int**)malloc(numRows * sizeof(int*));
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i ++) {
        array[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        array[i][0] = 1;
        array[i][i] = 1;
        
        for (int j = 1; j < i; j ++) {
            array[i][j] = array[i - 1][j] + array[i - 1][j - 1];
        }
    }

    
    return array;
}