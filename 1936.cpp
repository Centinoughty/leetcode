// Add minimum number of rungs
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int addRungs(vector<int>& rungs, int dist) {
    int prev = 0;
    int count = 0;

    for (const int x : rungs) {
      if (x - prev > dist) {
        count += ceil(static_cast<double>(x - prev) / dist) - 1;
      }

      prev = x;
    }

    return count;
  }
};
