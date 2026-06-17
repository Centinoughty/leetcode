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

// Memoisation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        memo.resize(n, -1);
        int round1 = robHelper(nums, n, 1);

        memo.assign(n, -1);
        int round2 = robHelper(nums, n - 1, 0);

        return max(round1, round2);
    }

private:
    vector<int> memo;

    int robHelper(vector<int>& nums, int n, int pos) {
        if (pos >= n) return 0;

        if (memo[pos] != -1) return memo[pos];

        int pick = nums[pos] + robHelper(nums, n, pos + 2);
        int noPick = robHelper(nums, n, pos + 1);

        return memo[pos] = max(pick, noPick);
    }
};

// Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp(n - 1, 0);
        for (int i = 0; i < n - 1; i ++) {
            int pick = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
            int noPick = (i - 1 >= 0 ? dp[i - 1] : 0);

            dp[i] = max(pick, noPick);
        }

        int round1 = dp[n - 2];

        dp.assign(n, 0);
        for (int i = 1; i < n; i ++) {
            int pick = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
            int noPick = (i - 1 >= 0 ? dp[i - 1] : 0);

            dp[i] = max(pick, noPick);
        }

        int round2 = dp[n - 1];

        return max(round1, round2);
    }
};
