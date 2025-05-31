// Sort colors
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int zero = 0, one = 0, two = 0;
    for (const int num : nums) {
      if (num == 0) {
        zero ++;
      } else if (num == 1) {
        one ++;
      } else {
        two ++;
      }
    }

    for (int i = 0; i < nums.size(); i ++) {
      if (zero) {
        nums[i] = 0;
        zero --;
      } else if (one) {
        nums[i] = 1;
        one --;
      } else {
        nums[i] = 2;
        two --;
      }
    }
  }
};

// Dutch National Flag Algorithm
class Solution {
public:
  void sortColors(vector<int>& nums) {
    int l = 0, mid = 0, r = nums.size() - 1;

    while (mid <= r) {
      if (nums[mid] == 0) {
        swap(nums[mid ++], nums[l ++]);
      } else if (nums[mid] == 1) {
        mid ++;
      } else {
        swap(nums[mid], nums[r --]);
      }
    }
  }
};
