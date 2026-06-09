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

// Solution 2

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int count = 0;
        while (!q.empty()) {
            int size = q.size();

            while (size --) {
                auto [x, y] = q.front(); q.pop();

                if (x > 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                }

                if (y > 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                }

                if (x < m - 1 && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                }

                if (y < n - 1 && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                }
            }

            count ++;
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return max(0, count - 1);
    }
};
