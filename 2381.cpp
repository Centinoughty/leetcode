// Shifting letters II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int curr = 0;
    vector<int> prefix(s.length() + 1);

    for (const vector<int>& shift : shifts) {
      int dir = shift[2] ? 1 : -1;
      prefix[shift[0]] += dir;
      prefix[shift[1] + 1] -= dir;
    }

    for (int i = 0; i < s.length(); i ++) {
      curr  =  (curr + prefix[i]) % 26;
      int num = (s[i] - 'a' + curr + 26) % 26;
      s[i] = 'a' + num;
    }

    return s;
  }
};
