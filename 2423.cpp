// Remove Letter To Equalize Frequency
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> mp;
        int maxFreq = INT_MIN, minFreq = INT_MAX;
        for (const char& c : word) {
            mp[c] ++;
            maxFreq = max(maxFreq, mp[c]);
            minFreq = min(minFreq, mp[c]);
        }

        for (const auto& [x, y] : mp) {
            unordered_map<char, int> temp = mp;
            temp[x] --;
            if (temp[x] == 0) temp.erase(x);

            unordered_map<int, int> freq;
            for (const auto& [a, b] : temp) {
                freq[b] ++;
            }

            if (freq.size() == 1) return true;
        }

        return false;
    }
};
