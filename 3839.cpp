// Number of prefix connected groups
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (const string& word : words) {
            if (word.length() >= k) {
                string s = word.substr(0, k);
                mp[s] ++;
            }
        }

        int res = 0;
        for (const auto [x, y] : mp) {
            if (y >= 2) {
                res ++;
            }
        }

        return res;
    }
};
