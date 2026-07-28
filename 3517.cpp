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

// O()
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        vector<int> mp(26, 0);
        for (const char& c : s) {
            mp[c - 'a'] ++;
        }

        char extra = '0';
        string res;

        for (int i = 0; i < 26; i ++) {
            if (mp[i] == 0) continue;
            
            if (mp[i] % 2) {
                extra = 'a' + i;
            }

            int cnt = mp[i] / 2;
            for (int j = 0; j < cnt; j ++) {
                res.push_back('a' + i);
            }
        }

        string temp = res;
        reverse(temp.begin(), temp.end());
        if (extra != '0') res.push_back(extra);

        res += temp;
        return res;
    }
};
