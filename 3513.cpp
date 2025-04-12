// Number of unique XOR triplets I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    }

    int high = 0;
    while (1 << (high + 1) <= n) {
      high ++;
    }

    return 1 << (high + 1);
  }
};