// Verifying an Alien Dictionary
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        int curr = 1;
        for (const char& c : order) {
            mp[c] = curr ++;
        }

        for (int i = 0; i < words.size() - 1; i ++) {
            int j = 0;
            int maxJ = min(words[i].size(), words[i + 1].size());
            while (j < maxJ) {
                if (words[i][j] == words[i + 1][j]) {
                    j ++;
                } else if (mp[words[i][j]] < mp[words[i + 1][j]]) {
                    break;
                } else {
                    return false;
                }
            }

            if (j == maxJ && words[i].size() > words[i + 1].size()) {
                return false;
            }
        }

        return true;
    }
};
