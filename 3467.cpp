// Transform array by parity
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> transformArray(vector<int>& nums) {
    int oddCnt = 0;
    for (int& num : nums) {
      num %= 2;
      oddCnt += num;
    }

    vector<int> res(nums.size(), 0);
    for (int i = nums.size() - oddCnt; i < nums.size(); i ++) {
      res[i] = 1;
    }

    return res;
  }
};