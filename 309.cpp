// Best Time to Buy and Sell Stock with Cooldown
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo.resize(n, vector<int>(2, -1));

        return profitHelper(prices, 0, 1);
    }

private:
    vector<vector<int>> memo;

    int profitHelper(vector<int>& prices, int pos, int buy) {
        if (pos >= prices.size()) return 0;

        if (memo[pos][buy] != -1) return memo[pos][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[pos] + profitHelper(prices, pos + 1, 0), profitHelper(prices, pos + 1, 1));
        } else {
            profit = max(prices[pos] + profitHelper(prices, pos + 2, 1), profitHelper(prices, pos + 1, 0));
        }

        return memo[pos][buy] = profit;
    }
};
