// Count symmetric integers
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSymmetricIntegers(int low, int high) {
    int res = 0;

    for (int i = low; i <= high; i ++) {
      string s = to_string(i);
      int len = s.length();
      if (len % 2) {
        continue;
      }

      int sumL = 0, sumR = 0;
      for (int j = 0; j < len / 2; j ++) {
        sumL += s[j] - '0';
      }

      for (int j = len / 2; j < len; j ++) {
        sumR += s[j] - '0';
      }

      if (sumL == sumR) {
        res ++;
      }
    }

    return res;
  }
};
