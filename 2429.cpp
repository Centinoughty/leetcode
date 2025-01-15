// Minimize XOR
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int res = num1;

    int c1 = noOfOne(num1);
    int c2 = noOfOne(num2);

    int curr = 0;

    while (c1 < c2) {
      if (!(res & (1 << curr))) {
        res |= (1 << curr);
        c1 ++;
      }

      curr ++;
    }

    while (c1 > c2) {
      if (res & (1 << curr)) {
        res &= ~(1 << curr);
        c1 --;
      }

      curr ++;
    }

    return res;
  }

private:
  int noOfOne (int n) {
    int count = 0;

    while (n) {
      if (n & 1) {
        count ++;
      }

      n >>= 1;
    }

    return count;
  }
};
