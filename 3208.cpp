// Alternating groups II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = colors.size();
    int count = 0;
    int l = 0, maxL = n + k - 1;
    while (l < n) {
      int r = l + 1;
      while (r < maxL && colors[(r - 1) % n] != colors[r % n]) {
        r ++;
      }

      if (r - l >= k) {
        count += r - l + 1 - k;
      }

      l = r;
    }

    return count;
  }
};
