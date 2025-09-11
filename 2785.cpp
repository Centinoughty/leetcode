// Sort vowels in a string
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vows;

        for (const char c : s) {
            char temp = tolower(c);
            if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
                vows.push_back(c);
            }
        }

        sort(vows.begin(), vows.end());

        int i = 0;
        for (char& c : s) {
            char temp = tolower(c);
            if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
                c = vows[i ++];
            }
        }

        return s;
    }
};
