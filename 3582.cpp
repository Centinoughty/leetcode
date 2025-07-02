// Generate tag for video caption
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string generateTag(string caption) {
        string res = "#";
        int len = 1;
        bool flag = false;
        for (const char c : caption) {
            if (len == 100) break;

            if (c == ' ') {
                flag = true;
            } else {
                if (res.size() == 1) {
                    res += tolower(c);
                    flag = false;
                } else if (flag) {
                    res += toupper(c);
                    flag = false;
                } else {
                    res += tolower(c);
                }

                len ++;
            }
        }

        return res;
    }
};
