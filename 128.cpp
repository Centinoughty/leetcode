// Longest consecutive sequence
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    int maxLength = 0;
    unordered_set<int> seen{nums.begin(), nums.end()};

    for (int x : nums) {
      if (!seen.count(x - 1)) {
        int length = 1;
        while (seen.erase(x + length)) {
          length ++;
        }

        maxLength = max(maxLength, length);
      }
    }

    return maxLength;
  }
};
