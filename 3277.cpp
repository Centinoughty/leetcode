// Vowels game in a string
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        for (const char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true;
            }
        }

        return false;
    }
};
