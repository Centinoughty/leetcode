// Construct k palindrome strings
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canConstruct(string s, int k) {
    int x = 0;
    vector<int>hash (26);
    if (s.length() < k) {
      return false;
    }

    for (const char ch : s) {
      hash[ch - 'a'] ++;
    }

    for (const int i : hash) {
      x += i & 1;
    }

    return x <= k;
  }
};
