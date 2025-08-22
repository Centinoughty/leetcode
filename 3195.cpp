// Find the minimum area to cover all ones I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l = INT_MAX, r = INT_MIN;
        int u = INT_MAX, b = INT_MIN;

        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    l = min(l, j + 1);
                    r = max(r, j + 1);
                    u = min(u, i + 1);
                    b = max(b, i + 1);
                }
            }
        }

        if (l == INT_MAX) return 0;

        return (r - l + 1) * (b - u + 1);
    }
};
