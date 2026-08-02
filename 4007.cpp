// Wildest Possible Fence
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        sort(planks.begin(), planks.end());

        unordered_map<int, int> mp, res;
        for (const int& plank : planks) {
            mp[plank] ++;
            res[plank] ++;
        }

        for (const auto p1 : mp) {
            for (const auto p2 : mp) {
                int a = p1.first, b = p2.first;
                if (a == b) {
                    res[a + b] += mp[a] / 2;
                } else if (a < b) {
                    res[a + b] += min(mp[a], mp[b]);
                }
            }
        }

        int maxWidth = 0;
        for (auto [x, y] : res) {
            maxWidth = max(maxWidth, y);
        }

        return maxWidth;
    }
};
