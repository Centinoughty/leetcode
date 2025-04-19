// Count the number of fair pairs
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    return count(nums, upper) - count(nums, lower - 1);
  }
private:
  long long count(vector<int>& nums, int val) {
    long long count = 0;
    int left = 0, right = nums.size() - 1;

    while (left < right) {
      while (left < right && nums[left] + nums[right] > val) {
        right --;
      }

      count += right - left;
      left ++;
    }

    return count;
  }
};
