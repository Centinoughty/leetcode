// Find the number of copy arrays
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
    int count = 0;
    int l = bounds[0][0], h = bounds[0][1];
    for (int i = 1; i < original.size(); i ++) {
      int diff = original[i] - original[i - 1];
      l = max(bounds[i][0], l + diff);
      h = min(bounds[i][1], h + diff);
    }

    if (l > h) {
      return 0;
    }

    return h - l + 1;
  }
};