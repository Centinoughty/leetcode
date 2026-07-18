// Rearrange String to Avoid Charecter Pair
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int cnt = 0;
        for (const char& c : s) {
            if (c == y) cnt ++;
        }

        string res = "";
        while (cnt --) {
            res.push_back(y);
        }

        for (const char& c : s) {
            if (c != y) res.push_back(c);
        }

        return res;
    }
};
