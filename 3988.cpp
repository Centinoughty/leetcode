// Create Grid With Exactly K Paths I
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<string> grid(m, string(n, '.'));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == 0 && j == 0 || i == m - 1 && j == n - 1) continue;

                grid[i][j] = '#';
                int cnt = count(grid);
                if (cnt == k) {
                    return grid;
                } else if (cnt < k) {
                    grid[i][j] = '.';
                }
            }
        }

        if (count(grid) == k) {
            return grid;
        }

        return {};
    }

private:
    int count(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> temp(m, vector<int>(n, 0));
        temp[0][0] = 1;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '#') {
                    temp[i][j] = 0;
                } else {
                    if (i > 0) temp[i][j] += temp[i - 1][j];
                    if (j > 0) temp[i][j] += temp[i][j - 1];
                }
            }
        }

        return temp[m - 1][n - 1];
    }
};
