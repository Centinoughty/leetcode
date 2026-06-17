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

// Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        for (int i = 0; i < nums.size(); i ++) {
            int pick = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
            int noPick = (i - 1 >= 0 ? dp[i - 1] : 0);
            dp[i] = max(pick, noPick);
        }

        return dp[nums.size() - 1];
    }
};
