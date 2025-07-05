// Number of enclaves
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i ++) {
            if (grid[i][0] == 1) {
                clearExits(grid, i, 0);
            }

            if (grid[i][grid[0].size() - 1] == 1) {
                clearExits(grid, i, grid[0].size() - 1);
            }
        }

        for (int j = 1; j < grid[0].size() - 1; j ++) {
            if (grid[0][j] == 1) {
                clearExits(grid, 0, j);
            }

            if (grid[grid.size() - 1][j] == 1) {
                clearExits(grid, grid.size() - 1, j);
            }
        }

        for (int i = 1; i < grid.size() - 1; i ++) {
            for (int j = 1; j < grid[0].size() - 1; j ++) {
                if (grid[i][j]) {
                    count ++;
                }
            }
        }

        return count;
    }

private:
    void clearExits(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size()) {
            return;
        }

        if (grid[i][j] == 1) {
            grid[i][j] = 0;
            clearExits(grid, i, j - 1);
            clearExits(grid, i - 1, j);
            clearExits(grid, i + 1, j);
            clearExits(grid, i, j + 1);
        }
    }
};
