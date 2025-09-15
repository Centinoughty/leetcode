// Maximum number of words you can type
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> mp(26, false);
        for (const char c : brokenLetters) {
            mp[c - 'a'] = true;
        }

        int count = 0;
        bool flag = true;
        
        text.push_back(' ');

        for (const char c : text) {
            if (c == ' ') {
                if (flag) {
                    count ++;
                } else {
                    flag = true;
                }
            } else {
                if (mp[c - 'a']) {
                    flag = false;
                }
            }
        }

        return count;
    }
};
