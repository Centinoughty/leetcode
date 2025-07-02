// Number of islands
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size(); j ++) {
                if (grid[i][j] == '1') {
                    count ++;
                    countHelper(grid, i, j);
                }
            }
        }

        return count;
    }

private:
    void countHelper(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size()) return;

        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            countHelper(grid, i - 1, j);
            countHelper(grid, i + 1, j);
            countHelper(grid, i, j - 1);
            countHelper(grid, i, j + 1);
        } 
    }
};
