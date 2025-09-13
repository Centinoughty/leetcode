// Find most frequent vowel and consonant
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> mp(26);
        for (const char c : s) {
            mp[c - 'a'] ++;
        }

        int vowCnt = 0, cnsCnt = 0;
        for (int i = 0; i < 26; i ++) {
            if (isVowel('a' + i)) {
                vowCnt = max(vowCnt, mp[i]);
            } else {
                cnsCnt = max(cnsCnt, mp[i]);
            }
        }

        return vowCnt + cnsCnt;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
