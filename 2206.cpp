// Divide array into equal pairs
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool divideArray(vector<int>& nums) {
    vector<int> hash(501, 0);
    for (const int num : nums) {
      hash[num] ++;
    }

    for (const int it : hash) {
      if (it % 2) {
        return false;
      }
    }

    return true;
  }
};
