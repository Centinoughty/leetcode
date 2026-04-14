// Maximum amount of money robot can earn
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        dp = coins;
        m = coins.size(); n = coins[0].size();
        memo.assign(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        return maxHelper(0, 0, 2);
    }

private:
    vector<vector<int>> dp;
    vector<vector<vector<int>>> memo;
    int m, n;

    int maxHelper(int i, int j, int rem) {
        if (i == m || j == n) return INT_MIN;

        if (i == m - 1 && j == n - 1) {
            if (dp[i][j] < 0 && rem > 0)
                return max(0, dp[i][j]);
            return dp[i][j];
        }

        if (memo[i][j][rem] != INT_MIN) return memo[i][j][rem];

        int a = INT_MIN, b = INT_MIN, c = INT_MIN, d = INT_MIN;

        if (rem > 0 && dp[i][j] < 0) {
            a = maxHelper(i, j + 1, rem - 1);
            b = maxHelper(i + 1, j, rem - 1);
        }

        c = maxHelper(i, j + 1, rem);
        d = maxHelper(i + 1, j, rem);

        if (c != INT_MIN) c += dp[i][j];
        if (d != INT_MIN) d += dp[i][j];

        return memo[i][j][rem] = max(max(a, b), max(c, d));
    }
};
