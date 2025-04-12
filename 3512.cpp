// Minimum operations to make array sum divisible by k
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    int sum = 0;
    for (const int num : nums) {
      sum += num;
    }

    return sum % k;
  }
};