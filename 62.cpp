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
