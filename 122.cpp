// Best Time to Buy and Sell Stock II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i --) {
            int buy = i, maxProfit = 0;
            for (int j = i + 1; j < n; j ++) {
                if (prices[j] < prices[buy]) {
                    buy = j;
                } else {
                    maxProfit = max(maxProfit, prices[j] - prices[buy] + dp[j]);
                }
            }

            dp[i] = maxProfit;
        }

        return dp[0];
    }
};

// Memoisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size(), vector<int>(2, -1));
        return profitHelper(prices, 0, 1);
    }

private:
    vector<vector<int>> memo;

    int profitHelper(vector<int>& prices, int pos, int buy) {
        if (pos == prices.size()) return 0;

        if (memo[pos][buy] != -1) return memo[pos][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[pos] + profitHelper(prices, pos + 1, 0), profitHelper(prices, pos + 1, 1));
        } else {
            profit = max(prices[pos] + profitHelper(prices, pos, 1), profitHelper(prices, pos + 1, 0));
        }

        return memo[pos][buy] = profit;
    }
};

// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i --) {
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            dp[i][0] = max(prices[i] + dp[i][1], dp[i + 1][0]);
        }

        return dp[0][1];
    }
};

// Optimal
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }

        return res;
    }
};
