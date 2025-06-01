// Majority element II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> hash;
    vector<int> res;
    for (const int num : nums) {
      hash[num] ++;
      if (hash[num] == nums.size() / 3 + 1) {
        res.push_back(num);
      }

      if (res.size() == 2) break;
    }

    return res;
  }
};
