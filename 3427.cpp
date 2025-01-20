// Sum of variable length subarrays
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums) {
    int res = 0;
    
    for (int i = 1; i < nums.size(); i ++) {
      nums[i] += nums[i - 1];
    }

    res += nums[0];
    for (int i = 1; i < nums.size(); i ++) {
      int start = max(0, i - nums[i] + nums[i - 1]);
      res += start > 0 ? nums[i] - nums[start - 1] : nums[i];
    }

    return res;
  }
};
