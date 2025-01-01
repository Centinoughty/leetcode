// Minimum flips to make a or b equal to c
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minFlips(int a, int b, int c) {
    int flipCount = 0;

    while (a || b || c) {
      if ((c & 1) && (!(a & 1) && !(b & 1))) {
        flipCount ++;
      } else if ((c & 1) == 0) {
        if (a & 1) {
          flipCount ++;
        }

        if (b & 1) {
          flipCount ++;
        }
      }

      c >>= 1;
      b >>= 1;
      a >>= 1;
    }

    return flipCount;
  }
};
