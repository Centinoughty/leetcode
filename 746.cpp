// Min cost climbing stairs
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n, -1);
        return min(fn(cost, n - 1), fn(cost, n - 2));
    }

private:
    vector<int> dp;

    int fn(vector<int>& cost, int pos) {
        if (pos < 0) return 0;
        if (pos == 0 || pos == 1) {
            return cost[pos];
        }

        if (dp[pos] != -1) return dp[pos];

        dp[pos] = cost[pos] + min(fn(cost, pos - 1), fn(cost, pos - 2));
        return dp[pos];
    }
};
