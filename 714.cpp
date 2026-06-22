// Best Time to Buy and Sell Stock with Transaction Fee
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memo.resize(n, vector<int>(2, -1));
        
        return profitHelper(prices, fee, 0, 1);
    }

private:
    vector<vector<int>> memo;

    int profitHelper(vector<int>& prices, int fee, int pos, int buy) {
        if (pos == prices.size()) return 0;

        if (memo[pos][buy] != -1) return memo[pos][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[pos] + profitHelper(prices, fee, pos + 1, 0), profitHelper(prices, fee, pos + 1, 1));
        } else {
            profit = max(prices[pos] - fee + profitHelper(prices, fee, pos, 1), profitHelper(prices, fee, pos + 1, 0));
        }

        return memo[pos][buy] = profit;
    }
};

// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i --) {
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);

            dp[i][0] = max(prices[i] - fee + dp[i][1], dp[i + 1][0]);
        }
        
        return dp[0][1];
    }
};
