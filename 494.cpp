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
