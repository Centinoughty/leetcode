// Count vowel strings in ranges
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> count(words.size() + 1, 0);
    vector<int> res;
    for (int i = 0; i < words.size(); i++) {
      if (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1])) {
        count[i + 1] = count[i] + 1;
      } else {
        count[i + 1] = count[i];
      }
    }

    for (int i = 0; i < words.size() + 1; i++) {
      cout << count[i] << " ";
    }

    for (auto query : queries) {
      int l = query[0];
      int r = query[1];

      res.push_back(count[r + 1] - count[l]);
    }

    return res;
  }

private:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
