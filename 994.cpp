// Rotting oranges
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int maxTime = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            pair<pair<int, int>, int> temp = q.front();
            q.pop();
            int time = temp.second;
            maxTime = max(maxTime, time);

            int i = temp.first.first, j = temp.first.second;

            if (i > 0 && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                q.push({{i - 1, j}, time + 1});
            }

            if (j > 0 && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push({{i, j - 1}, time + 1});
            }

            if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push({{i, j + 1}, time + 1});
            }

            if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                q.push({{i + 1, j}, time + 1});
            }
        }

        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return maxTime;
    }
};
