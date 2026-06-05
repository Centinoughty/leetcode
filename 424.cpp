// Longest Repeating Charecter Replacement
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> mp;
        
        int l = 0, maxFreq = 0;
        int res = 0;
        for (int r = 0; r < s.length(); r ++) {
            mp[s[r]] ++;
            maxFreq = max(maxFreq, mp[s[r]]);

            while ((r - l + 1) - maxFreq > k) {
                mp[s[l ++]] --;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
