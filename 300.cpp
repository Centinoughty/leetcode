// Longest increasing subsequence
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        dp = vector<vector<int>>(nums.size(), vector<int>(nums.size() + 1, -1));
        return fn(nums, 0, -1);
    }

private:
    vector<vector<int>> dp;

    int fn(vector<int>& nums, int pos, int prev) {
        if (pos == nums.size()) return 0;

        if (dp[pos][prev + 1] != -1) return dp[pos][prev + 1];

        int l1, l2;
        if (prev == -1 || nums[pos] > nums[prev]) {
            l1 = 1 + fn(nums, pos + 1, pos);
        }

        l2 = fn(nums, pos + 1, prev);
        dp[pos][prev + 1] = max(l1, l2);

        return dp[pos][prev + 1];
    }
};
