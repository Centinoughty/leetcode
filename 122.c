// Best time to buy and sell stock II
// MEDIUM

#include <stdio.h>
#include <limits.h>
#include <math.h>

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int hold = INT_MIN;

    for (int i = 0; i < pricesSize; i ++) {
        profit = fmax(profit, hold + prices[i]);
        hold = fmax(hold, profit - prices[i]);
    }

    return profit;
}