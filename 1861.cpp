// Rotating the box
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();

        vector<vector<char>> rotBox;
        for (int i = 0; i < m; i ++) {
            int prev = n;
            for (int j = n - 1; j >= 0; j --) {
                if (boxGrid[i][j] == '*') {
                    prev = j;
                } else if (boxGrid[i][j] == '#') {
                    boxGrid[i][j] = '.';
                    boxGrid[i][prev - 1] = '#';
                    prev -= 1;
                }
            }
        }

        rotBox = transform(boxGrid);
        return rotBox;
    }

private:
    vector<vector<char>> transform(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<char>> rotBox(n, vector<char>(m, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                rotBox[j][m - i - 1] = grid[i][j];
            }
        }

        return rotBox;
    }
};
