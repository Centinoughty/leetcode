// Richest customer wealth

#include <stdio.h>

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int maximum = 0;
    for (int i = 0; i < accountsSize; i ++) {
        int sum = 0;
        for (int j = 0; j < *accountsColSize; j ++) {
            sum += accounts[i][j];
        }

        maximum = sum >= maximum ? sum : maximum;
    }

    return maximum;
}