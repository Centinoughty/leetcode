// Number of Longest Increasing Subsequence
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    } else if (dp[i] ==  1 + dp[j]) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int res = 0;
        int maxVal = *max_element(dp.begin(), dp.end());
        for (int i = 0; i < n; i ++) {
            if (dp[i] == maxVal) {
                res += count[i];
            }
        }

        return res;
    }
};
