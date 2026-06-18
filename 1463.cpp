// Cherry Pickup II
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memo.resize(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return pathHelper(grid, 0, 0, n - 1);
    }

private:
    vector<vector<vector<int>>> memo;

    int pathHelper(vector<vector<int>>& grid, int lvl, int y1, int y2) {
        int m = grid.size(), n = grid[0].size();
        if (lvl == m) return 0;

        if (memo[lvl][y1][y2] != -1) return memo[lvl][y1][y2];

        int maxVal = INT_MIN;
        for (int pos1 = max(0, y1 - 1); pos1 <= min(n - 1, y1 + 1); pos1 ++) {
            for (int pos2 = max(0, y2 - 1); pos2 <= min(n - 1, y2 + 1); pos2 ++) {
                maxVal = max(maxVal, pathHelper(grid, lvl + 1, pos1, pos2));
            }
        }

        if (y1 == y2) return memo[lvl][y1][y2] = grid[lvl][y1] + maxVal;
        return memo[lvl][y1][y2] = grid[lvl][y1] + grid[lvl][y2] + maxVal;
    }
};
