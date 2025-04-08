// Minimum number of operations to make elements in array distinct
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    vector<int> hash(101, 0);
    int i;
    for (i = nums.size() - 1; i >= 0; i --) {
      if (!hash[nums[i]]) {
        hash[nums[i]] ++;
      } else {
        break;
      }
    }

    return ceil((float)(i + 1) / 3);
  }
};
