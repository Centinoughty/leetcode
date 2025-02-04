// Longest strictly increasing or decreasing subarray
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int inc = 1, dec = 1;
    int length = 1;

    for (int i = 1; i < nums.size(); i ++) {
      if (nums[i] > nums[i - 1]) {
        inc ++;
        dec = 1;
      } else if (nums[i] < nums[i - 1]) {
        dec ++;
        inc = 1;
      } else {
        inc = 1;
        dec = 1;
      }

      length = max({length, inc, dec});
    }

    return length;
  }
};
