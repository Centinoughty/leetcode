// Best time to buy and sell stock
// EASY

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int min = 0;
    int max = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < prices[min]) {
            min = i;
        } else {
            int profit = prices[i] - prices[min];
            max = profit > max ? profit : max;
        }
    }

    return max;
}