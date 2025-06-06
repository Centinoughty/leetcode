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
