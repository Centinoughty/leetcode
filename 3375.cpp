// Minimum operations to make array values equal to k
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    set<int> unique(nums.begin(), nums.end());
    int res = 0;

    for (const int num : unique) {
      if (num > k) {
        res ++;
      } else if (num < k) {
        return -1;
      }
    }

    return res;
  }
};
