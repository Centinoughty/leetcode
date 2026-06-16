// Process String with Special Operations I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string res;
        for (const char c : s) {
            if (isLower(c)) {
                res.push_back(c);
            } else if (c == '#') {
                res += res;
            } else if (c == '%') {
                reverse(res.begin(), res.end());
            } else {
                if (res.size() > 0) {
                    res.pop_back();
                }
            }
        }

        return res;
    }

private:
    bool isLower(char c) {
        return 'a' <= c && c <= 'z';
    }
};
