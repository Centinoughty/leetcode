// Shortest path in binary matrix
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] || grid[n - 1][n - 1]) return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            int dist = grid[x][y];
            if (x == n - 1 && y == n - 1) {
                return dist;
            }

            for (int i = -1; i < 2; i ++) {
                for (int j = -1; j < 2; j ++) {
                    int u = x + i, v = y + j;
                    if (i == j && i == 0) continue;
                    if (u < 0 || v < 0 || u == n || v == n) continue;
                    if (grid[u][v]) continue;
                    q.push({u, v});
                    grid[u][v] = dist + 1;
                }
            }
        }

        return -1;
    }
};
