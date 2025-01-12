// Check if a parentheses string can be valid
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canBeValid(string s, string locked) {
    int length = s.length();
    if (length % 2) {
      return false;
    }

    stack<int> open;
    stack<int> unlocked;

    for (int i = 0; i < length; i ++) {
      if (locked[i] == '0') {
        unlocked.push(i);
      } else if (s[i] == '(') {
        open.push(i);
      } else if (s[i] == ')') {
        if (!open.empty()) {
          open.pop();
        } else if (!unlocked.empty()) {
          unlocked.pop();
        } else {
          return false;
        }
      }
    }

    while (!open.empty() && !unlocked.empty() && open.top() < unlocked.top()) {
      open.pop();
      unlocked.pop();
    }

    if (open.empty() && !unlocked.empty()) {
      return open.size() % 2 == 0;
    }

    return open.empty();
  }
};