// Coin change II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> dp;

    int bfs(vector<int>& coins, int pos, int amount) {
        if (amount == 0) return 1;
        if (amount < 0) return 0;

        if (dp[pos][amount] != -2) return dp[pos][amount];

        int count = 0;
        for (int i = pos; i < coins.size(); i ++) {
            int temp = bfs(coins, i, amount - coins[i]);
            count += temp;
        }

        dp[pos][amount] = count;
        return dp[pos][amount];
    }

public:
    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -2));
        int res = bfs(coins, 0, amount);
        return res;
    }
};
