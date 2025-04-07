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
