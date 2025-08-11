// Sort charecters by frequency
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (const char& c : s) {
            mp[c] ++;
        }

        vector<pair<int, char>> vc;
        for (const auto& [c, k] : mp) {
            vc.push_back({k, c});
        }

        sort(vc.begin(), vc.end(), [](const pair<int, char>& a, const pair<int, char>& b) {return a.first > b.first;});
        string res;
        for (const auto& [k, c] : vc) {
            for (int i = 0; i < k; i ++) {
                res.push_back(c);
            }
        }

        return res;
    }
};
