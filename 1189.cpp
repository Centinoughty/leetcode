// Maximum Number of Balloons
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        for (const char c : text) {
            if (isBalloon(c)) {
                mp[c] ++;
            }
        }

        if (mp.size() < 5) return 0;

        int minCount = INT_MAX;
        for (const auto& [x, y] : mp) {
            if (x == 'l' || x == 'o') {
                minCount = min(minCount, y / 2);
            } else {
                minCount = min(minCount, y);
            }
        }

        return minCount;
    }

private:
    bool isBalloon(char c) {
        return c == 'a' || c == 'b' || c == 'l' || c == 'n' || c == 'o';
    }
};
