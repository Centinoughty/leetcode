// Palindromic substrings
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int len = s.length();
        for (int i = 0; i < len; i ++) {
            int l = i, r = i;
            while (l >= 0 && r < len && s[l] == s[r]) {
                l --;
                r ++;

                count ++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < len && s[l] == s[r]) {
                l --;
                r ++;

                count ++;
            }
        }

        return count;
    }
};