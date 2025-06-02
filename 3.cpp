// Longest substring without repeating charecters
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int length = 0, maxLength = 0, start = 0;
    unordered_map<char, int> seen;
    for (int i = 0; i < s.length(); i ++) {
      if (seen.find(s[i]) == seen.end() || seen[s[i]] < start) {
        seen[s[i]] = i;
        length ++;
        maxLength = max(maxLength, length);
      } else {
        start = seen[s[i]] + 1;
        length = i - seen[s[i]];
        seen[s[i]] = i;
      }
    }

    return maxLength;
  }
};
