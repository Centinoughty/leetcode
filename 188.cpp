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

// Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int i = n - 1; i >= 0; i --) {
            for (int j = 1; j <= k; j ++) {
                dp[i][1][j] = max(-prices[i] + dp[i + 1][0][j], dp[i + 1][1][j]);

                dp[i][0][j] = max(prices[i] + dp[i][1][j - 1], dp[i + 1][0][j]);
            }
        }

        return dp[0][1][k];
    }
};
