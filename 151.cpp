// Reverse words in a string
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == ' ') {
                i ++;
                continue;
            }

            int j = i;
            while (j < s.length() && s[j] != ' ') {
                j ++;
            }

            string temp = s.substr(i, j - i);
            reverse(temp.begin(), temp.end());
            res += temp + ' ';
            i = j + 1;
        }

        reverse(res.begin(), res.end() - 1);
        if (res[res.length() - 1] == ' ') {
            res.pop_back();
        }

        return res;
    }
};
