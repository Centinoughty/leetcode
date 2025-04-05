// Sum of all subsets xor totals
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subsetXORSum(vector<int>& nums) {
    int res = 0;

    for (const int num : nums) {
      res |= num;
    }

    return res << (nums.size() - 1);
  }
};
