// Maximum count of positive integer and negative integer
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumCount(vector<int>& nums) {
    int pos = 0, neg = 0;
    for (const int num : nums) {
      if (num > 0) {
        pos ++;
      } else if (num < 0) {
        neg ++;
      }
    }

    return max(pos, neg);
  }
};
