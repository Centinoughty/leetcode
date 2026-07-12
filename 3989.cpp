// Maximum Consistent Columns in a Grid
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 1);
        int res = 1;
        for (int j = 0; j < n; j ++) {
            for (int i = 0; i < j; i ++) {
                if (check(grid, i, j, limit)) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }

            res = max(res, dp[j]);
        }

        return res;
    }

private:
    bool check(vector<vector<int>>& grid, int a, int b, int lim) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i ++) {
            if (abs(grid[i][b] - grid[i][a]) > lim) return false;
        }

        return true;
    }
};
