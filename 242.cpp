// Valid anagrams
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> mp(26, 0);
        for (const char c : s) {
            mp[c - 'a'] ++;
        }

        for (const char c : t) {
            if (mp[c - 'a'] > 0) {
                mp[c - 'a'] --;
            } else {
                return false;
            }
        }

        return true;
    }
};
