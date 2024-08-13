// Convert the temperature

#include <stdio.h>

double* convertTemperature(double celsius, int* returnSize) {
    double* array = (double*)malloc(2 * sizeof(double));
    *returnSize = 2;
    array[0] = celsius + 273.15;
    array[1] = celsius * 1.8 + 32.00;

    return array;
}