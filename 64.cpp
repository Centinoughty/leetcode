// Minimum path sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return dfs(grid, m - 1, n - 1);
    }

private:
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x == 0 && y == 0) {
            return grid[0][0];
        }

        if (x < 0 || y < 0) {
            return INT_MAX;
        }

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int up = dfs(grid, x - 1, y);
        int left = dfs(grid, x, y - 1);
        grid[x][y] += min(up, left);
        dp[x][y] = grid[x][y];
        return grid[x][y];
    }
};
