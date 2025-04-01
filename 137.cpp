// Single number II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> map;
    for (const int num : nums) {
      map[num] ++;
    }

    for (auto num : map) {
      if (num.second == 1) {
        return num.first;
      }
    }

    return -1;
  }
};
