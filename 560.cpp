// Subarray sum equals k
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i ++) {
      int sum = 0;
      for (int j = i; j < nums.size(); j ++) {
        sum += nums[j];
        if (sum == k) {
          count ++;
        }
      }
    }

    return count;
  }
};

// Optimal solution

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int> mp;

        int prefix = 0;
        for (int i = 0; i < nums.size(); i ++) {
            prefix += nums[i];
            if (prefix == k) {
                cnt ++;
            }

            if (mp.find(prefix - k) != mp.end()) cnt += mp[prefix - k];

            mp[prefix] ++;
        }

        return cnt;
    }
};
