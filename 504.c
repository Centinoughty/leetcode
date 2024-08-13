// Base 7
// EASY

#include <stdio.h>
#include <stdlib.h>

char* convertToBase7(int num) {
    char* string = (char*)malloc(32 * sizeof(char));
    if (num == 0) {
        string[0] = '0';
        string[1] = '\0';
        return string;
    }
    
    int pos = 0;
    int sign = num >= 0 ? 1 : -1;
    int x = sign * num;
    while (x != 0) {
        string[pos ++] = (char)(x % 7 + '0');
        x /= 7;
    }

    if (sign == -1) {
        string[pos ++] = '-';
    }
    string[pos] = '\0';
    int left = 0, right = pos - 1;
    while (left < right) {
        char temp = string[left];
        string[left] = string[right];
        string[right] = temp;

        left ++;
        right --;
    }

    return string;
}