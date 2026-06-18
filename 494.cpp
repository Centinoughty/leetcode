// Target sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dp = vector<vector<int>>(4001, vector<int>(nums.size(), -2));

        return targetSumHelper(nums, target, 0);
    }

private:
    vector<vector<int>> dp;

    int targetSumHelper(vector<int>& nums, int target, int pos) {
        if (pos == nums.size()) {
            return target == 0;
        }

        if (dp[target + 2000][pos] != -2) return dp[target + 2000][pos];

        int l = targetSumHelper(nums, target - nums[pos], pos + 1);
        int r = targetSumHelper(nums, target + nums[pos], pos + 1);

        dp[target + 2000][pos] = l + r;
        return dp[target + 2000][pos];
    }
};

// Tabulation
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

        dp[n][sum] = 1;
        for (int i = n - 1; i >= 0; i --) {
            for (int j = -sum; j <= sum; j ++) {
                int count = 0;
                if (j - nums[i] >= -sum) count += dp[i + 1][j - nums[i] + sum];
                if (j + nums[i] <= sum) count += dp[i + 1][j + nums[i] + sum];

                dp[i][j + sum] = count;
            }
        }

        return dp[0][target + sum];
    }
};
