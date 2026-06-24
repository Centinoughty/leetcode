// Partition Array for Maximum Sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memo.resize(n, -1);
        return maxHelper(arr, 0, k);
    }

private:
    vector<int> memo;

    int maxHelper(vector<int>& nums, int l, int k) {
        if (l == nums.size()) return 0;

        if (memo[l] != -1) return memo[l];

        int val = 0, maxi = nums[l];
        for (int i = l; i < l + k && i < nums.size(); i ++) {
            maxi = max(maxi, nums[i]);
            val = max(val, (i - l + 1) * maxi + maxHelper(nums, i + 1, k));
        }

        return memo[l] = val;
    }
};

// Tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i --) {
            int val = 0, maxVal = arr[i];
            for (int j = i; j < min(n, i + k); j ++) {
                maxVal = max(maxVal, arr[j]);
                val = max(val, (j - i + 1) * maxVal + dp[j + 1]);
            }

            dp[i] = val;
        }

        return dp[0];
    }
};
