// Cyclically rotating a grid
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int levels = min(m / 2, n / 2);

        for (int lvl = 0; lvl < levels; lvl ++) {
            vector<int> temp, r, c;

            for (int i = lvl; i < m - lvl - 1; i ++) {
                r.push_back(i);
                c.push_back(lvl);
                temp.push_back(grid[i][lvl]);
            }

            for (int j = lvl; j < n - lvl - 1; j ++) {
                r.push_back(m - lvl - 1);
                c.push_back(j);
                temp.push_back(grid[m - lvl - 1][j]);
            }

            for (int i = m - lvl - 1; i > lvl; i --) {
                r.push_back(i);
                c.push_back(n - lvl - 1);
                temp.push_back(grid[i][n - lvl - 1]);
            }

            for (int j = n - lvl - 1; j > lvl; j --) {
                r.push_back(lvl);
                c.push_back(j);
                temp.push_back(grid[lvl][j]);
            }

            int newK = k % temp.size();

            for (int i = 0; i < temp.size(); i ++) {
                int pos = (i + temp.size() - newK) % temp.size();
                grid[r[i]][c[i]] = temp[pos];
            }
        }

        return grid;
    }
};
