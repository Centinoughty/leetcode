// Predict the winner
// MEDIUM

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool predictTheWinner(vector<int>& nums) {
    int numsSize = nums.size();
    vector<int> array = nums;

    for (int i = 1; i < numsSize; i++) {
      for (int j = numsSize - 1; j - i >= 0; j--) {
        array[j] = max(nums[j - i] - array[j], nums[j] - array[j - 1]);
      }
    }

    return array[numsSize - 1] >= 0;
  }
};

// Memoisation
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, vector<int>(n, -1));
        return helper(nums, 0, nums.size() - 1) >= 0;
    }

private:
    vector<vector<int>> memo;

    int helper(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];

        if (memo[l][r] != -1) return memo[l][r];

        return memo[l][r] = max(nums[l] - helper(nums, l + 1, r), nums[r] - helper(nums, l, r - 1));
    }
};

// Tabulation
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i --) {
            dp[i][i] = nums[i];
            for (int j = i + 1; j < n; j ++) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};
