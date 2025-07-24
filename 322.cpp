// Coin change
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> dp;

    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        if (dp[amount] != -2) return dp[amount];

        int count = INT_MAX;
        for (const int coin : coins) {
            int res = dfs(coins, amount - coin);
            if (res >= 0) {
                count = min(count, res + 1);
            }
        }

        dp[amount] = count == INT_MAX ? -1 : count;
        return dp[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, -2);
        return dfs(coins, amount);
    }
};
