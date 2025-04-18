// Count and say
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string res = "1";
    for (int i = 1; i < n; i ++) {
      res = rle(res);
    }

    return res;
  }
private:
  string rle(string s) {
    string res;
    int i = 0;
    while (i < s.length()) {
      char c = s[i];
      int count = 0;
      int j = i;
      while (j < s.length() && s[i] == s[j]) {
        count ++;
        j ++;
      }

      res += to_string(count);
      res += s[i];
      i = j;
    }

    return res;
  }
};
