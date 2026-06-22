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

private:
    vector<int> memo;

    int profitHelper(vector<int>& prices, int pos) {
        if (pos == prices.size()) return 0;

        if (memo[pos] != -1) return memo[pos];

        int buy = pos, maxProfit = 0;
        for (int i = pos + 1; i < prices.size(); i ++) {
            if (prices[i] < prices[buy]) {
                buy = i;
            } else {
                maxProfit = max(maxProfit, prices[i] - prices[buy] + profitHelper(prices, i));
            }
        }

        return memo[pos] = maxProfit;
    }
};
