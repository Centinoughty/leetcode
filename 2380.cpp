// Time needed to rearrange a binary tree
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int secondsToRemoveOccurrences(string s) {
    int zeroes = 0, res = 0;
    
    for (const char c : s) {
      if (c == '0') {
        zeroes ++;
      } else if (zeroes > 0) {
        res = max(res + 1, zeroes);
      }
    }

    return res;
  }
};
