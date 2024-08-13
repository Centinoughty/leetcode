// Predict the winner
// MEDIUM

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool predictTheWinner(vector<int>& nums) {
    int numsSize = nums.size();
    vector<int> array = nums;

    for (int i = 1; i < numsSize; i++) {
      for (int j = numsSize - 1; j - i >= 0; j--) {
        array[j] = max(nums[j - i] - array[j], nums[j] - array[j - 1]);
      }
    }

    return array[numsSize - 1] >= 0;
  }
};