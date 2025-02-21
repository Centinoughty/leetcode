// Find unique binary string
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string findDifferentBinaryString(vector<string>& nums) {
    int length = nums.size();
    vector<int> hash(1 << length, 0);

    for (int i = 0; i < length; i ++) {
      int number = stoi(nums[i], NULL, 2);
      hash[number] = 1;
    }

    for (int i = 0; i < 1 << length; i ++) {
      if (!hash[i]) {
        bitset<16> binary(i);
        return binary.to_string().substr(16 - length);
      }
    }

    return "";
  }
};
