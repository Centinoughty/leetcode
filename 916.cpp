// Word subsets
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<int> maxCount(26, 0);

    for (const string word : words2) {
      vector<int> count(26, 0);
      for (const char ch : word) {
        count[ch - 'a']++;
      }

      for (int i = 0; i < 26; i++) {
        maxCount[i] = max(maxCount[i], count[i]);
      }
    }

    vector<string> res;
    for (const string word : words1) {
      vector<int> count (26, 0);
      for (const char ch : word) {
        count[ch - 'a'] ++;
      }

      int flag = 1;
      for (int i = 0; i < 26; i ++) {
        if (count[i] < maxCount[i]) {
          flag = 0;
          break;
        }
      }

      if (flag) {
        res.push_back(word);
      }
    }

    return res;
  }
};
