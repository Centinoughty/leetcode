// House robber
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return fn(nums, 0);
    }

private:
    vector<int> dp;

    int fn(vector<int>& nums, int pos) {
        if (pos >= nums.size()) return 0;

        if (dp[pos] != -1) return dp[pos];

        dp[pos] = max(nums[pos] + fn(nums, pos + 2), fn(nums, pos + 1));
        return dp[pos];
    }
};
