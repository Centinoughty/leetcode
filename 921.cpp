// Minimum Add to Make Parentheses Valid
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        int cnt = 0;
        for (const char& c : s) {
            if (c == '(') {
                cnt ++;
            } else {
                cnt --;
                if (cnt < 0) {
                    res ++;
                    cnt = 0;
                }
            }
        }

        res += cnt;
        return res;
    }
};
