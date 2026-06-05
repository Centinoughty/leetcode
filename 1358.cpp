// Number of Substrings Containing All Three Charecters
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> mp(3, 0);

        int l = 0, cnt = 0;
        for (int r = 0; r < s.length(); r ++) {
            mp[s[r] - 'a'] ++;

            while (mp[0] && mp[1] && mp[2]) {
                cnt += s.length() - r;

                mp[s[l] - 'a'] --;
                l ++;
            }
        }

        return cnt;
    }
};
