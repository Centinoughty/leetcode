// House robber II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> s1(nums.begin(), nums.end() - 1);
        vector<int> s2(nums.begin() + 1, nums.end());

        int n = nums.size() - 1;

        dp = vector<int>(n, -1);
        int t1 = max(fn(s1, n - 1), fn(s1, n - 2));
        
        dp = vector<int>(n, -1);
        int t2 = max(fn(s2, n - 1), fn(s2, n - 2));

        return max(t1, t2);
    }

private:
    vector<int> dp;

    int fn(vector<int>& nums, int pos) {
        if (pos < 0) return 0;
        if (pos == 0 || pos == 1) return nums[pos];

        if (dp[pos] != -1) return dp[pos];

        int i = fn(nums, pos - 2);
        int j = fn(nums, pos - 3);
        dp[pos] = nums[pos] + max(i, j);

        return dp[pos];
    }
};
