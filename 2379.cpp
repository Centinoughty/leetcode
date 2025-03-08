// Minimum recolors to get K consecutive black blocks
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int count = 0, maxCount = 0;
    for (int i = 0; i < blocks.size(); i ++) {
      if (blocks[i] == 'B') {
        count ++;
      }

      if (i >= k && blocks[i - k] == 'B') {
        count --;
      }

      maxCount = max(maxCount, count);
    }

    return k - maxCount;
  }
};
