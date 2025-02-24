// Check if digits are equal in string after operations I
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool hasSameDigits(string s) {
    int length = s.length();
    for (int i = 0; i < length - 2; i ++) {
      string temp;
      for (int i = 0; i < s.length() - 1; i ++) {
        temp += (s[i] + s[i + 1] - 2 * '0') % 10 + '0';
      }

      s = temp;
    }

    return s[0] == s[1];
  }
};
