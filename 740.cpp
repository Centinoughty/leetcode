// Delete and earn
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    vector<int> hash(10001);

    for (const int num : nums) {
      hash[num] += num;
    }

    int p1 = 0;
    int p2 = 0;
    for (const int val : hash) {
      int temp = max(p1, val + p2);
      p2 = p1;
      p1 = temp;
    }

    return p1;
  }
};
