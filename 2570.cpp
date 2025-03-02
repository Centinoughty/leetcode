// Merge two 2D array by summing values
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    vector<int> hash(1000, 0);
    vector<vector<int>> res;

    for (int i = 0; i < nums1.size(); i ++) {
      hash[nums1[i][0] - 1] += nums1[i][1];
    }

    for (int i = 0; i < nums2.size(); i ++) {
      hash[nums2[i][0] - 1] += nums2[i][1];
    }

    for (int i = 0; i < 1000; i ++) {
      if (hash[i]) {
        res.push_back({i + 1, hash[i]});
      }
    }

    return res;
  }
};
