// Maximum absolute sum of any subarray
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxAbsoluteSum(vector<int>& nums) {
    int maxi = 0, mini = 0;
    int cnt = 0;

    for (const int num : nums) {
      cnt += num;
      maxi = max(maxi, cnt);
      mini = min(mini, cnt);
    }

    return maxi - mini;
  }
};