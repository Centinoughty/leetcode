// Unique paths
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    grid[0][0] = 1;

    for (int i = 0; i < m; i ++) {
      for (int j = 0; j < n; j ++) {
        grid[i][j] += j > 0 ? grid[i][j - 1] : 0;
        grid[i][j] += i > 0 ? grid[i - 1][j] : 0;
      }
    }

    return grid[m - 1][n - 1];
  }
};

// Memoisation
class Solution {
public:
    int uniquePaths(int m, int n) {
        memo.resize(m, vector<int>(n, -1));
        return pathHelper(m, n, 0, 0);
    }

private:
    vector<vector<int>> memo;

    int pathHelper(int m, int n, int x, int y) {
        if (x == m || y == n) return 0;

        if (memo[x][y] != -1) return memo[x][y];

        if (x == m - 1 && y == n - 1) return 1;

        int res = pathHelper(m, n, x + 1, y) + pathHelper(m, n, x, y + 1);

        return memo[x][y] = res;
    }
};
