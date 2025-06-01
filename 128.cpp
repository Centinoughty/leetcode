// Longest consecutive sequence
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    int maxLength = 0;
    unordered_set<int> mpp(nums.begin(), nums.end());
    for (const int num : nums) {
      if (!mpp.count(num - 1)) {
        int length = 1;
        while (mpp.erase(num + length)) {
          length ++;
        }

        maxLength = max(maxLength, length);
      }
    }

    return maxLength;
  }
};

// Using sort
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());
    int num = nums[0];
    int count = 1, maxCount = 1;
    for (int i = 1; i < nums.size(); i ++) {
      if (nums[i] == nums[i - 1]) continue;
      else if (nums[i] == num + count) {
        count ++;
        maxCount = max(maxCount, count);
      } else {
        num = nums[i];
        count = 1;
      }
    }

    return maxCount;
  }
};
