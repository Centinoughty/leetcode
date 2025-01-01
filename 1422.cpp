// Maximum score after splitting a string
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxScore(string s) {
    int length = s.size();
    vector<int> left(length - 1, 0);
    vector<int> right(length - 1, 0);
    int zeroCount = 0;
    int oneCount = 0;
    int maxCount = 0;

    for (int i = 1; i < length; i ++) {
      if (s[i - 1] == '0') {
        zeroCount ++;
        left[i - 1] = zeroCount;
      }
    }

    for (int i = length - 2; i >= 0; i --) {
      if (s[i + 1] == '1') {
        oneCount ++;
        right[i] = oneCount;
      }
    }

    for (int i = 0; i < length - 1; i ++) {
      maxCount = max(maxCount, left[i] + right[i]);
    }

    return maxCount;
  }
};
