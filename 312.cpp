// Burst Balloons
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(1);
        for (const int& num : nums) {
            temp.push_back(num);
        }

        temp.push_back(1);
        int n = nums.size();
        memo.resize(n + 1, vector<int>(n + 1, -1));

        return costHelper(temp, 1, nums.size());
    }

private:
    vector<vector<int>> memo;

    int costHelper(vector<int>& nums, int l, int r) {
        int n = nums.size();
        if (r < l) return 0;

        if (memo[l][r] != -1) return memo[l][r];

        int res = INT_MIN;
        for (int k = l; k <= r; k ++) {
            int cost = nums[l - 1] * nums[k] * nums[r + 1];
            res = max(res, cost + costHelper(nums, l, k - 1) + costHelper(nums, k + 1, r));
        }

        return memo[l][r] = res;
    }
};

// Tabulation
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(1);
        for (const int& num : nums) {
            temp.push_back(num);
        }

        temp.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i > 0; i --) {
            for (int j = i; j <= n; j ++) {
                int res = INT_MIN;
                for (int k = i; k <= j; k ++) {
                    int cost = temp[i - 1] * temp[k] * temp[j + 1];
                    res = max(res, cost + dp[i][k - 1] + dp[k + 1][j]);
                }

                dp[i][j] = res;
            }
        }

        return dp[1][n];
    }
};
