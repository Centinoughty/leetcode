// Find the Safest Path in a Grid
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    dist[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!q.empty()) {
            auto [node, w] = q.front(); q.pop();
            auto [x, y] = node;

            if (dist[x][y] < w) continue;

            for (const auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx == m || ny == n) continue;

                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({{nx, ny}, dist[nx][ny]});
                }
            }
        }

        int res = 0;
        int l = 0, r = min(dist[0][0], dist[m - 1][n - 1]);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (canReach(dist, mid)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }

private:
    bool canReach(vector<vector<int>>& dist, int lim) {
        if (dist[0][0] < lim) return false;

        int m = dist.size(), n = dist[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        
        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (x == m - 1 && y == n - 1) return true;

            for (const auto& [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;

                if (nx < 0 || ny < 0 || nx == m || ny == n) continue;

                if (dist[nx][ny] < lim) continue;

                if (vis[nx][ny]) continue;

                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        return false;
    }
};
