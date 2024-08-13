// Multiply strings
// MEDIUM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int size1 = strlen(num1);
    int size2 = strlen(num2);
    int size = size1 + size2;
    int* array = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i ++) {
        array[i] = 0;
    }
    
    for (int i = size1 - 1; i >= 0; i--) {
        for (int j = size2 - 1; j >= 0; j--) {
            int product = ((num1[i] - '0') * (num2[j] - '0')) + array[i + j + 1];
            array[i + j] += product / 10;
            array[i + j + 1] = product % 10;
        }
    }
    
    int zeroCount = 0;
    while (zeroCount < size - 1 && array[zeroCount] == 0) {
        zeroCount++;
    }
    
    char* string = (char*)malloc((size - zeroCount + 1) * sizeof(char));
    int pos = 0;
    for (int i = zeroCount; i < size; i++) {
        string[pos ++] = array[i] + '0';
    }

    string[pos] = '\0';
    free(array);
    return string;
}