// String matching in an array
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> res;
    
    for (int i = 0; i < words.size(); i ++) {
      for (int j = 0; j < words.size(); j ++) {
        if (i != j) {
          size_t idx = words[j].find(words[i]);
          if (idx != string::npos) {
            res.push_back(words[i]);
            break;
          }
        }
      }
    }

    return res;
  }
};
