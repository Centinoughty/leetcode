// String compression III
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string compressedString(string word) {
    string res = "";
    int length = word.size();
    char prev = word[0];
    int count = 0;

    for (int i = 0; i < length; i++) {
      if (prev == word[i]) {
        count++;

        if (count == 9) {
          res += '9';
          res += prev;
          count = 0;
        }
      } else {
        if (count) {
          res += to_string(count);
          res += prev;
        }

        count = 1;
      }

      prev = word[i];
    }

    if (count) {
      res += to_string(count);
      res += prev;
    }

    return res;
  }
};
