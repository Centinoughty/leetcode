// Largest divisible subset
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    int maxIdx = 0;

    for (int i = 1; i < n; i ++) {
      for (int j = 0; j < i; j ++) {
        if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }

      if (dp[i] > dp[maxIdx]) {
        maxIdx = i;
      }
    }

    vector<int> res;
    while(maxIdx >= 0) {
      res.push_back(nums[maxIdx]);
      maxIdx = prev[maxIdx];
    }

    return res;
  }
};
