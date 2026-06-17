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

// Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] += i > 0 ? dp[i - 1][j] : 0;
                    dp[i][j] += j > 0 ? dp[i][j - 1] : 0;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};