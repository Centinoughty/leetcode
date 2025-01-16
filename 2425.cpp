// Bitwise xor of all pairings
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int res = 0;
    int m = nums1.size();
    int n = nums2.size();

    for (const int i : nums1) {
      res ^= n % 2 ? i : 0;
    }

    for (const int j : nums2) {
      res ^= m % 2 ? j : 0;
    }

    return res;
  }
};
