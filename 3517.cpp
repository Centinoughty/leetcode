// Smallest palindromic rearrangement I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string smallestPalindrome(string s) {
    int length = s.length();
    string newStr = s.substr(0, length / 2);
    sort(newStr.begin(), newStr.end());

    string reversed = newStr;
    reverse(reversed.begin(), reversed.end());

    string middle = "";
    if (length % 2) {
      middle += s[length / 2];
    }

    string res = newStr + middle + reversed;
    return res;
  }
};
