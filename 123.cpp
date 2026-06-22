// Best Time to Buy and Sell Stock III
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = n - 1; i >= 0; i --) {
            for (int k = 1; k <= 2; k ++) {
                dp[i][1][k] = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);

                dp[i][0][k] = max(prices[i] + dp[i][1][k - 1], dp[i + 1][0][k]);
            }
        }

        return dp[0][1][2];
    }
};

// Memoisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo.resize(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return profitHelper(prices, 0, 1, 2);
    }

private:
    vector<vector<vector<int>>> memo;

    int profitHelper(vector<int>& prices, int pos, int buy, int cnt) {
        if (cnt < 0 || pos == prices.size()) return 0;

        if (memo[pos][buy][cnt] != -1) return memo[pos][buy][cnt];

        int profit = 0;
        if (buy) {
            profit = max(-prices[pos] + profitHelper(prices, pos + 1, 0, cnt - 1), profitHelper(prices, pos + 1, 1, cnt));
        } else {
            profit = max(prices[pos] + profitHelper(prices, pos, 1, cnt), profitHelper(prices, pos + 1, 0, cnt));
        }

        return memo[pos][buy][cnt] = profit;
    }
};
