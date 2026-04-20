// Two furthest houses with different colors
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res = INT_MIN;
        for (int i = 0; i < colors.size(); i ++) {
            for (int j = i + 1; j < colors.size(); j ++) {
                if (colors[i] != colors[j]) {
                    res = max(res, j - i);
                }
            }
        }

        return res;
    }
};
