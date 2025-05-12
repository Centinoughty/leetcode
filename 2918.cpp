// Minimum equal sum of two arrays after replacing zeroes
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long s1 = 0, s2 = 0;
    int n1 = 0, n2 = 0;

    for (const int num : nums1) {
      s1 += num;
      if (num == 0) {
        n1 ++;
        s1 ++;
      }
    }

    for (const int num : nums2) {
      s2 += num;
      if (num == 0) {
        n2 ++;
        s2 ++;
      }
    }

    if (!n1 && s2 > s1 || !n2 && s1 > s2) {
      return -1;
    }

    return max(s1, s2);
  }
};
