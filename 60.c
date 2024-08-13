// Permutation sequence
// HARD

#include <stdio.h>
#include <stdlib.h>

int factorial (int n) {
    int product = 1;
    for (int i = 2; i <= n; i ++) {
        product *= i;
    }

    return product;
}


char* getPermutation(int n, int k) {
    char* string = (char*)malloc((n + 1) * sizeof(char));
    int* set = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i ++) {
        set[i] = i + 1;
    }

    int x = n;
    k --;
    for (int i = 0; i < n; i ++) {
        int index = k / factorial(x - 1);
        string[i] = (char)(set[index] + '0');
        for (int j = index; j < x - 1; j ++) {
            set[j] = set[j + 1];
        }

        k %= factorial(x -1);
        x --;
    }

    string[n] = '\0';
    free(set);
    return string;
}