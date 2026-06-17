// Unique Paths II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        memo.resize(m, vector<int>(n, -1));

        return pathHelper(obstacleGrid, 0, 0);
    }

private:
    vector<vector<int>> memo;

    int pathHelper(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if (x == m || y == n) return 0;

        if (memo[x][y] != -1) return memo[x][y];

        if (grid[x][y] == 1) return 0;
        if (x == m - 1 && y == n - 1) return 1;

        int res = pathHelper(grid, x + 1, y) + pathHelper(grid, x, y + 1);
        return memo[x][y] = res;
    }
};
