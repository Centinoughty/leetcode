// Check if one string swap can make strings equal
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    char pos1, pos2;
    int count = 0;

    for (int i = 0; i < s1.size(); i ++) {
      if (s1[i] != s2[i]) {
        if (count >= 2) {
          return false;
        }

        if (count) {
            if (pos1 != s2[i] || pos2 != s1[i]) {
              return false;
            }
        } else {
          pos1 = s1[i];
          pos2 = s2[i];
        }

        count ++;
      }
    }

    return !(count % 2);
  }
};
