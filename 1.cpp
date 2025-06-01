// Two sum
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i ++) {
      for (int j = i + 1; j < nums.size(); j ++) {
        if (nums[i] + nums[j] == target) {
          res.push_back(i);
          res.push_back(j);
          return res;
        }
      }
    }

    return res;
  }
};

// Using hash
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i ++) {
      int num = nums[i];
      int needed = target - num;
      if (hash.find(needed) != hash.end()) {
        return {i, hash[needed]};
      }

      hash[num] = i;
    }

    return {-1, -1};
  }
};
