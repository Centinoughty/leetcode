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

// Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i --) {
            for (int prev = i - 1; prev >= -1; prev --) {
                int noPick = dp[i + 1][prev + 1];
                int pick = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    pick = 1 + dp[i + 1][i + 1];
                }

                dp[i][prev + 1] = max(pick, noPick);
            }
        }

        return dp[0][0];
    }
};

// Optimal
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
