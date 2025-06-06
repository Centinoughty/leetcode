// Remove duplicates from sorted array
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    set<int> all;
    int count = 0;
    for (const int num : nums) {
      if (all.find(num) == all.end()) {
        count ++;
      }

      all.insert(num);
    }

    for (int i = 0; i < count; i ++) {
      nums[i] = *all.begin();
      all.erase(all.begin());
    }

    return count;
  }
};

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    int j = i + 1;
    while (j < nums.size()) {
      if (nums[i] == nums[j]) {
        j ++;
      } else {
        nums[i + 1] = nums[j];
        i ++;
        j ++;
      }
    }

    return i + 1;
  }
};
