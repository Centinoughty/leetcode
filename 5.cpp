// Longest palindromic substring
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.length(); i ++) {
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l --;
                r ++;
            }

            if (r - l - 1 > res.length()) {
                res = s.substr(l + 1, r - l - 1);
            }

            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l --;
                r ++;
            }

            if (r - l - 1 > res.length()) {
                res = s.substr(l + 1, r - l - 1);
            }
        }

        return res;
    }
};
