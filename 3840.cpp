// House robber V
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        dp = vector<long long>(nums.size(), -1);

        return robHelper(nums, colors, nums.size() - 1);
    }

private:
    vector<long long> dp;
    
    long long robHelper(vector<int>& nums, vector<int>& colors, int pos) {
        if (pos < 0) return 0;
        if (pos == 0) return nums[0];

        if (dp[pos] != -1) return dp[pos];

        long long res = robHelper(nums, colors, pos - 1);
        if (colors[pos] == colors[pos - 1]) {
            res = max(res, nums[pos] + robHelper(nums, colors, pos - 2));
        } else {
            res = max(res, nums[pos] + robHelper(nums, colors, pos - 1));
        }

        dp[pos] = res;
        return dp[pos];
    }
};
