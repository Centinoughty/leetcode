// Counting words with a given prefix
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int prefixCount(vector<string>& words, string pref) {
    int count = 0;

    for (const string word : words) {
      if (word.starts_with(pref)) {
        count ++;
      }
    }

    return count;
  }
};
