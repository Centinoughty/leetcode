// Bulls and cows
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string getHint(string secret, string guess) {
    int length = secret.size();
    vector<int> hs(10, 0);
    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < length; i ++) {
      if (secret[i] == guess[i]) {
        bulls ++;
      } else {
        hs[secret[i] - '0'] ++;
      }
    }

    for (int i = 0; i < length; i ++) {
      if (secret[i] != guess[i]) {
        if (hs[guess[i] - '0']) {
          cows ++;
          hs[guess[i] - '0'] --;
        }
      }
    }

    string res = "";
    res += to_string(bulls);
    res += "A",
    res += to_string(cows);
    res += "B";
    return res;
  }
};
