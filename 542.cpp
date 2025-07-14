// 01 matrix
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (const auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};
