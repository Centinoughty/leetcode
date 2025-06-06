// Max consective ones
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int length = 0, maxLength = 0;
    for (const int num : nums) {
      if (num == 1) {
        length ++;
        maxLength = max(maxLength, length);
      } else {
        length = 0;
      }
    }

    return maxLength;
  }
};
