// Partition equal subset sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int total = 0;
    for (const int num : nums) {
      total += num;
    }

    if (total % 2) {
      return false;
    }

    unordered_set<int> dp;
    dp.insert(0);
    for (const int num : nums) {
      unordered_set<int> copy = dp;
      for (const int x : dp) {
        copy.insert(x + num);
      }

      dp = copy;
      if (dp.count(total / 2)) {
        return true;
      }
    }

    return false;
  }
};

// Memoisation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2) return false;

        int n = nums.size();
        memo.resize(n, vector<int>(totalSum / 2 + 1, -1));

        return sumHelper(nums, 0, totalSum / 2);
    }

private:
    vector<vector<int>> memo;

    bool sumHelper(vector<int>& nums, int pos, int k) {
        if (pos == nums.size()) {
            if (k == 0) return true;
            return false;
        }

        if (memo[pos][k] != -1) return memo[pos][k];

        bool noPick = sumHelper(nums, pos + 1, k);
        bool pick = false;
        if (k - nums[pos] >= 0) {
            pick = sumHelper(nums, pos + 1, k - nums[pos]);
        }

        return memo[pos][k] = pick || noPick;
    }
};
