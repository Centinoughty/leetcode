// Best Time to Buy and Sell Stock IV
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        memo.resize(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        
        return profitHelper(prices, 0, 1, k);
    }


private:
    vector<vector<vector<int>>> memo;

    int profitHelper(vector<int>& prices, int pos, int buy, int k) {
        if (k == 0 || pos == prices.size()) return 0;

        if (memo[pos][buy][k] != -1) return memo[pos][buy][k];

        int profit = 0;
        if (buy) {
            profit = max(-prices[pos] + profitHelper(prices, pos + 1, 0, k), profitHelper(prices, pos + 1, 1, k));
        } else {
            profit = max(prices[pos] + profitHelper(prices, pos, 1, k - 1), profitHelper(prices, pos + 1, 0, k));
        }

        return memo[pos][buy][k] = profit;
    }
};
