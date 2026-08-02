// Count Valid Prefixes
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidPrefixes(string s) {
        int res = 0;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < s.length(); i ++) {
            char c = s[i];
            cnt0 += c - '0' == 0;
            cnt1 += c - '0' == 1;

            if (i % 2) {
                if (abs(cnt0 - cnt1) == 0) res ++;
            } else {
                if (abs(cnt0 - cnt1) == 1) res ++;
            }
        }

        return res;
    }
};
