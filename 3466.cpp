// Sort matrix by diagonals
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i ++) {
            vector<int> temp;
            for (int j = 0; j < n && i + j < n; j ++) {
                temp.push_back(grid[j][i + j]);
            }

            sort(temp.begin(), temp.end());
            for (int j = 0; j < n && i + j < n; j ++) {
                grid[j][i + j] = temp[j];
            }
        }

        for (int i = 0; i < n; i ++) {
            vector<int> temp;
            for (int j = 0; j < n && i + j < n; j ++) {
                temp.push_back(grid[i + j][j]);
            }

            sort(temp.begin(), temp.end(), greater<int>());
            for (int j = 0; j < n && i + j < n; j ++) {
                grid[i + j][j] = temp[j];
            }
        }

        return grid;
    }
};
