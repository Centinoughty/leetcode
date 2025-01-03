// Number of ways to split array
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int waysToSplitArray(vector<int>& nums) {
    vector<long> res(nums.size(), 0);
    res[0] = nums[0];
    int count = 0;
    for (int i = 1; i < nums.size(); i ++) {
        res[i] = nums[i] + res[i - 1];
    }

    for (int i = 0; i < nums.size() - 1; i ++) {
      if (res[i] >= res[nums.size() - 1] - res[i]) {
        count ++;
      }
    }

    return count;
  }
};
