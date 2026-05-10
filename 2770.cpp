// Maximum number of jumps to reach the last index
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        memo = vector<int>(nums.size(), INT_MIN);

        int res = dfs(nums, target, 0);
        return res < 0 ? -1 : res;
    }

private:
    vector<int> memo;

    int dfs(vector<int>& nums, int target, int pos) {
        if (pos == nums.size() - 1) return 0;

        if (memo[pos] != INT_MIN) return memo[pos];

        int res = INT_MIN;
        for (int i = pos + 1; i < nums.size(); i ++) {
            if (abs(nums[i] - nums[pos]) <= target) {
                res = max(res, dfs(nums, target, i) + 1);
            }
        }

        memo[pos] = res;
        return memo[pos];
    }
};

// DP Solution

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = 0;

        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (abs(nums[i] - nums[j]) <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1] < 0 ? -1 : dp[n - 1];
    }
};
